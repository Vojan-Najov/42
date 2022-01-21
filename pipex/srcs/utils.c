#include "pipex.h"

void	ft_waiting(t_ppx *ppx, int *status)
{
	if (waitpid(ppx->pid1, status, 0) == -1)
	{
		perror(ppx->argv1[0]);
		exit(EXIT_FAILURE);
	}
	if (waitpid(ppx->pid2, status, WUNTRACED) == -1)
	{
		perror(ppx->argv2[0]);
		exit(EXIT_FAILURE);
	}
}

void	ft_free(t_ppx *ppx)
{
	int	i;

	i = -1;
	if (ppx->paths)
	{
		while (ppx->paths[++i])
			free(ppx->paths[i]);
		free(ppx->paths);
	}
	i = -1;
	free(ppx->path_name1);
	free(ppx->path_name2);
	if (ppx->argv1)
		while (ppx->argv1[++i])
			free(ppx->argv1[i]);
	i = -1;
	free(ppx->argv1);
	if (ppx->argv2)
		while (ppx->argv2[++i])
			free(ppx->argv2[i]);
	free(ppx->argv2);
}
