#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

#define SIMPLE_COMMAND 0
#define PIPELINE 1

static const char	g_cd_arg[] = "error: cd: bad arguments\n";

static const char	g_cd_err[] = "error: cd: cannot "\
								  "change directory to ";

static const char	g_fatal[] = "error: fatal\n";

static const char	g_exe_err[] = "error: cannot execute ";

static size_t	strtab_len(char **path);

static size_t	ft_strlen(char *s);

static int	ft_cd(char **path);

static void	free_cmds(char ***cmds);

static size_t	cmds_len(char **argv, char *delimeter);

static size_t	cmd_len(char **argv, char *delimeter);

static char	***split_into_cmds(char **argv, char *delimeter);

static int	execution(char **args, char **envp);

static int	check_args(char **args);

static int	execute_simple(char **args, char **envp);

static int	execute_pipeline(char **args, char **envp);

static pid_t	execute_cmd(char **args, char **envp, int fd_for_close);

static int	wait_childs(pid_t *pid, int n);

int	main(int argc, char **argv, char **envp)
{
	char	***cmds;
	int		ret;

	if (argc == 1 || (argc == 2 && !strcmp(argv[1], ";")))
		return (0);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	cmds = split_into_cmds(argv + 1, ";");
	for(int i = 0; cmds[i]; ++i)
		ret = execution(cmds[i], envp);
	free_cmds(cmds);
	return (ret);
}

static int	execution(char **args, char **envp)
{
	int	ret;

	ret = check_args(args);
	if (ret == SIMPLE_COMMAND)
		ret = execute_simple(args, envp);
	else
		execute_pipeline(args, envp);
	return (ret);
}

static int execute_simple(char **args, char **envp)
{
	pid_t	pid;
	int		status;

	if (!strcmp(*args, "cd"))
	{
		return (ft_cd(args + 1));
	}
	pid = fork();
	if (pid == -1)
	{
		write(STDERR_FILENO, g_fatal, sizeof(g_fatal) - 1);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		execve(*args, args, envp);
		write(STDERR_FILENO, g_exe_err, sizeof(g_exe_err) - 1);
		write(STDERR_FILENO, *args, ft_strlen(*args));
		write(STDERR_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}
	if (waitpid(pid, &status, 0) == -1)
	{
		write(STDERR_FILENO, g_fatal, sizeof(g_fatal) - 1);
		exit(EXIT_FAILURE);
	}
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		status = WTERMSIG(status);
	return (status);
}

static int	execute_pipeline(char **args, char **envp)
{
	char	***cmds;
	int		fd[2];
	int		n;
	pid_t	*pid;
	int		fd_for_close;
	int		ret;
	int		save0;
	int		save1;

	fd_for_close = -1;
	ret = 0;
	save0 = dup(STDIN_FILENO);
	save1 = dup(STDOUT_FILENO);
	
	cmds = split_into_cmds(args, "|");
	n = 0;
	while (cmds[n])
		++n;
	pid = (pid_t *) malloc(sizeof(pid_t) * n);
	if (!pid)
	{
		write(STDERR_FILENO, g_fatal, sizeof(g_fatal) - 1);
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < n; ++i)
	{
		if (i == 0)
		{
			pipe(fd);
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
			fd_for_close = fd[0];
		}
		else if (i == n - 1)
		{
			dup2(fd[0], STDIN_FILENO);
			close (fd[0]);
			dup2(save1, STDOUT_FILENO);
		}
		else
		{
			dup2(fd[0], STDIN_FILENO);
			close (fd[0]);
			pipe(fd);
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
			fd_for_close = fd[0];
		}
		pid[i] = execute_cmd(cmds[i], envp, fd_for_close);
	}
	dup2(save0, STDIN_FILENO);
	dup2(save1, STDOUT_FILENO);
	ret = wait_childs(pid, n);
	close(save0);
	close(save1);
	free_cmds(cmds);
	return(ret);
}

static int	wait_childs(pid_t *pid, int n)
{
	int	status;

	status = 0;
	for (int i = 0; i < n; ++i)
	{
		if (waitpid(pid[i], &status, 0) == -1)
		{
			write(STDERR_FILENO, g_fatal, sizeof(g_fatal) - 1);
			exit(EXIT_FAILURE);
		}
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			status = WTERMSIG(status);
	}
	free(pid);
	return (status);
}

static pid_t	execute_cmd(char **args, char **envp, int fd_for_close)
{
	pid_t	pid;
	int		ret;

	pid = fork();
	if (pid == -1)
	{
		write(STDERR_FILENO, g_fatal, sizeof(g_fatal) - 1);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (fd_for_close != -1)
			close(fd_for_close);
		if (!strcmp(*args, "cd"))
		{
			ret = ft_cd(args + 1);
			exit(ret);
		}
		execve(*args, args, envp);
		write(STDERR_FILENO, g_exe_err, sizeof(g_exe_err) - 1);
		write(STDERR_FILENO, *args, ft_strlen(*args));
		write(STDERR_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}
	return (pid);
}

static void	free_cmds(char ***cmds)
{
	for(int i = 0; cmds[i]; ++i)
		free(cmds[i]);
	free(cmds);
}

static int	check_args(char **args)
{
	while (*args)
	{
		if (!strcmp(*args, "|"))
			return (PIPELINE);
		++args;
	}
	return (SIMPLE_COMMAND);
}

static char	***split_into_cmds(char **argv, char *delimeter)
{
	int		n;
	char	***cmds;


	n = cmds_len(argv, delimeter);
	cmds = (char ***) malloc(sizeof(char **) * (n + 1));
	if (!cmds)
	{
		write(STDERR_FILENO, g_fatal, sizeof(g_fatal) - 1);
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < n; ++i)
	{
		int k = cmd_len(argv, delimeter);
		cmds[i] = (char **) malloc(sizeof(char *) * (k + 1));
		if (!cmds[i])
		{
			write(STDERR_FILENO, g_fatal, sizeof(g_fatal) - 1);
			exit(EXIT_FAILURE);
		}
		for (int j = 0; j < k; ++j)
		{
			cmds[i][j] = *argv;
			++argv;
		}
		cmds[i][k] = NULL;
		++argv;
	}
	cmds[n] = NULL;
	
/*	for (int i = 0; cmds[i]; ++i)
	{
		for (int j = 0; cmds[i][j]; ++j)
		{
			printf("_%s_", cmds[i][j]);
		}
		printf("\n");
	}
*/
	return (cmds);
}

static size_t	cmd_len(char **argv, char *delimeter)
{
	size_t	k;

	k = 0;
	while (*argv)
	{
		if (!strcmp(*argv, delimeter))
			break ;
		++k;
		++argv;
	}
	return (k);
}

static size_t	cmds_len(char **argv, char *delimeter)
{
	size_t	n;
	char	**ptr;

	n = 1;
	ptr = argv;
	while (*argv)
	{
		if (!strcmp(*argv, delimeter) && *(argv + 1) && (argv != ptr))
		{
			++n;
		}
		++argv;
	}
	return (n);
}

static int	ft_cd(char **path)
{
	int		ret;
	size_t	i;

	i = strtab_len(path);
	if (i != 1)
	{
		write(STDERR_FILENO, g_cd_arg, sizeof(g_cd_arg) - 1);
		return (1);
	}
	ret = chdir(path[0]);
	if (ret == -1)
	{
		write(STDERR_FILENO, g_cd_err, sizeof(g_cd_err) - 1);
		write(STDERR_FILENO, path[0], ft_strlen(path[0]));
		write(STDERR_FILENO, "\n", 1);
		return (1);
	}
	return (0);
}

static size_t	ft_strlen(char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		++l;
	return (l);
}

static size_t	strtab_len(char **path)
{
	size_t	i;

	i = 0;
	while (path[i])
		++i;
	return (i);
}
