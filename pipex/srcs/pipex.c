/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:38:30 by ccartman          #+#    #+#             */
/*   Updated: 2022/01/17 20:35:31 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	open_fds(t_ppx *ppx, char *input, char *output);

static void	first_proccess(t_ppx *ppx, char **envp);

static void	second_process(t_ppx *ppx, char **envp);

static void	pipex(t_ppx *ppx, char **envp);

int	main(int argc, char **argv, char **envp)
{
	t_ppx	ppx;
	int		status;

	if (argc != 5)
	{
		write(STDERR_FILENO, g_arg_err, sizeof(g_arg_err) - 1);
		return (ARG_ERROR);
	}
	ft_memset(&ppx, 0, sizeof(t_ppx));
	ppx.paths = get_paths(envp);
	if (!find_cmd1(&ppx, argv[2]) || !find_cmd2(&ppx, argv[3]))
	{
		return (CMD_ERROR);
	}
	open_fds(&ppx, argv[1], argv[argc - 1]);
	pipex(&ppx, envp);
	close(ppx.fd[0]);
	close(ppx.fd[1]);
	ft_free(&ppx);
	status = 0;
	ft_waiting(&ppx, &status);
	return (status);
}

static void	open_fds(t_ppx *ppx, char *input, char *output)
{
	int	ret;

	ppx->fd_input = open(input, O_RDONLY);
	if (ppx->fd_input == -1)
	{
		perror(input);
		ft_free(ppx);
		exit(EXIT_FAILURE);
	}
	ppx->fd_output = open(output, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (ppx->fd_output == -1)
	{
		perror(output);
		ft_free(ppx);
		exit(EXIT_FAILURE);
	}
	ret = pipe(ppx->fd);
	if (ret)
	{
		perror("pipe");
		ft_free(ppx);
		exit(EXIT_FAILURE);
	}
}

static void	first_proccess(t_ppx *ppx, char **envp)
{
	close(ppx->fd[0]);
	if (dup2(ppx->fd_input, STDIN_FILENO) == -1)
	{
		ft_free(ppx);
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(ppx->fd_input);
	if (dup2(ppx->fd[1], STDOUT_FILENO) == -1)
	{
		ft_free(ppx);
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(ppx->fd[1]);
	execve(ppx->path_name1, ppx->argv1, envp);
	perror(ppx->argv1[0]);
	exit(EXIT_FAILURE);
}

static void	second_process(t_ppx *ppx, char **envp)
{
	close(ppx->fd[1]);
	if (dup2(ppx->fd_output, STDOUT_FILENO) == -1)
	{
		ft_free(ppx);
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(ppx->fd_output);
	if (dup2(ppx->fd[0], STDIN_FILENO) == -1)
	{
		ft_free(ppx);
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(ppx->fd[0]);
	execve(ppx->path_name2, ppx->argv2, envp);
	perror(ppx->argv2[0]);
	exit(EXIT_FAILURE);
}

static void	pipex(t_ppx *ppx, char **envp)
{
	ppx->pid1 = fork();
	if (ppx->pid1 == -1)
	{
		perror("fork");
		ft_free(ppx);
		exit(EXIT_FAILURE);
	}
	if (ppx->pid1 == 0)
	{
		first_proccess(ppx, envp);
	}	
	ppx->pid2 = fork();
	if (ppx->pid2 == -1)
	{
		perror("fork");
		ft_free(ppx);
		exit(EXIT_FAILURE);
	}
	if (ppx->pid2 == 0)
	{
		second_process(ppx, envp);
	}
}
