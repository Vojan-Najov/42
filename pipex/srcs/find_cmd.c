#include "pipex.h"

static char	*find_cmd(t_ppx *ppx, char **path_name, char *cmd);

static char	*check_cmd(char *cmd, char **path_name, t_ppx *ppx)
{
	if (access(cmd, F_OK) == 0)
	{
		*path_name = ft_strdup(cmd);
		if (!*path_name)
		{
			write(STDERR_FILENO, g_mem_err, sizeof(g_mem_err) - 1);
			ft_free(ppx);
			exit(EXIT_FAILURE);
		}
		return (*path_name);
	}
	return (NULL);
}

char	*find_cmd1(t_ppx *ppx, char *cmd1)
{
	ppx->argv1 = ft_split(cmd1, ' ');
	check_cmd(ppx->argv1[0], &ppx->path_name1, ppx);
	if (ppx->path_name1)
		return (ppx->path_name1);
	find_cmd(ppx, &ppx->path_name1, ppx->argv1[0]);
	if (ppx->path_name1)
		return (ppx->path_name1);
	write(STDERR_FILENO, ppx->argv1[0], ft_strlen(ppx->argv1[0]));
	write(STDERR_FILENO, g_cmd_err, sizeof(g_cmd_err) - 1);
	ft_free(ppx);
	return (NULL);
}

char	*find_cmd2(t_ppx *ppx, char *cmd2)
{
	ppx->argv2 = ft_split(cmd2, ' ');
	check_cmd(ppx->argv2[0], &ppx->path_name2, ppx);
	if (ppx->path_name2)
		return (ppx->path_name2);
	find_cmd(ppx, &ppx->path_name2, ppx->argv2[0]);
	if (ppx->path_name2)
		return (ppx->path_name2);
	write(STDERR_FILENO, cmd2, ft_strlen(cmd2));
	write(STDERR_FILENO, g_cmd_err, sizeof(g_cmd_err) - 1);
	ft_free(ppx);
	return (NULL);
}

static char	*find_cmd(t_ppx *ppx, char **path_name, char *cmd)
{
	int	i;

	i = 0;
	if (!ppx->paths)
		return (NULL);
	while (ppx->paths[i])
	{
		*path_name = ft_strjoin(ppx->paths[i], cmd);
		if (!*path_name)
		{
			write(STDERR_FILENO, g_mem_err, sizeof(g_mem_err) - 1);
			ft_free(ppx);
			exit(EXIT_FAILURE);
		}
		if (access(*path_name, X_OK) == 0)
			return (*path_name);
		free(*path_name);
		*path_name = NULL;
		++i;
	}
	return (NULL);
}
