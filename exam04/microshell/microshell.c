#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

static const char	g_cd_arg[] = "error: cd: bad arguments\n";

static const char	g_cd_err[] = "error: cd: cannot "\
								  "change directory to ";

static const char	g_fatal[] = "error: fatal\n";

static size_t	strtab_len(const char **path);

static size_t	ft_strlen(const char *s);

static int	ft_cd(const char **path);

static size_t	cmds_len(char **argv);

static size_t	cmd_len(char **argv);

int	main(int argc, char **argv, char **envp)
{
	const char	*path[]	= {".", NULL};
	int	n;
	char	***cmds;

	if (argc == 1 || (argc == 2 && !strcmp(argv[1], ";")))
		return (0);
	(void) argv;
	(void) envp;
	(void) ft_cd(path);
	n = cmds_len(argv + 1);
	printf("n is %d\n", n);
	cmds = (char ***) malloc(sizeof(char **) * (n + 1));
	if (!cmds)
	{
		write(STDERR_FILENO, g_fatal, sizeof(g_fatal) - 1);
		exit(EXIT_FAILURE);
	}
	argv++;
	for (int i = 0; i < n; ++i)
	{
		int k = cmd_len(argv);
		cmds[i] = (char **) malloc(sizeof(char *) * (k + 1));
		for (int j = 0; j < k; ++j)
		{
			cmds[i][j] = *argv;
			++argv;
		}
		cmds[i][k] = NULL;
		++argv;
	}
	cmds[n] = NULL;
	for (int i = 0; cmds[i]; ++i)
	{
		for (int j = 0; cmds[i][j]; ++j)
		{
			printf("_%s_", cmds[i][j]);
		}
		printf("\n");
	}
	return (0);
}

static size_t	cmd_len(char **argv)
{
	size_t	k;

	k = 0;
	while (*argv)
	{
		if (!strcmp(*argv, ";"))
			break ;
		++k;
		++argv;
	}
	printf("k is %d\n", (int) k);
	return (k);
}

static size_t	cmds_len(char **argv)
{
	size_t	n;
	char	**ptr;

	n = 1;
	ptr = argv;
	while (*argv)
	{
		if (!strcmp(*argv, ";") && *(argv + 1) && (argv != ptr))
		{
			++n;
		}
		++argv;
	}
	return (n);
}

static int	ft_cd(const char **path)
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
		return (1);
	}
	return (0);
}

static size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		++l;
	return (l);
}

static size_t	strtab_len(const char **path)
{
	size_t	i;

	i = 0;
	while (path[i])
		++i;
	return (i);
}
