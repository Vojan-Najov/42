/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:39:28 by ccartman          #+#    #+#             */
/*   Updated: 2022/01/17 18:19:11 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

#define ARG_ERROR 1
#define PATH_ERROR 2
#define FD_ERROR 3
#define CMD_ERROR 4

static const char	g_arg_err[] = "Error: Incorrect arguments\n";
//static const char	g_path_err[] = "Error: PATH not found\n";
static const char	g_mem_err[] = "Error: memory not allocated\n";
static const char	g_cmd_err[] = " : command not found\n";

typedef struct s_ppx
{
	char	**paths;
	char	*path_name1;
	char	*path_name2;
	char	**argv1;
	char	**argv2;
	int		fd_input;
	int		fd_output;
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
}			t_ppx;

char	**get_paths(char **envp);

char	*find_cmd1(t_ppx *ppx, char *cmd1);

char	*find_cmd2(t_ppx *ppx, char *cmd2);

void	ft_free(t_ppx *ppx);

void	ft_waiting(t_ppx *ppx, int *status);

#endif
