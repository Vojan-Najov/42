/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_fds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:19:27 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/14 21:24:24 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static int	fd_error(char *name);

static int	dup2_error(int fd);

int	redirect_fds(t_redirect	**redirect)
{
	size_t	i;
	int		fd;

	i = -1;
	while (redirect[++i])
	{
		fd = -1;
		if (redirect[i]->type & REDIRECT_INPUT)
			fd = open(redirect[i]->name, O_RDONLY);
		else if (redirect[i]->type & REDIRECT_OUTPUT)
			fd = open(redirect[i]->name, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		else if (redirect[i]->type & REDIRECT_APPEND)
			fd = open(redirect[i]->name, O_WRONLY | O_CREAT | O_APPEND, 0666);
		else if (redirect[i]->type & REDIRECT_HEREDOC)
			fd = open(redirect[i]->name, O_RDONLY);
		if (fd == -1)
			return (fd_error(redirect[i]->name));
		if (dup2(fd, redirect[i]->fd) == -1)
			return (dup2_error(redirect[i]->fd));
		close(fd);
	}
	return (1);
}

static int	fd_error(char *name)
{
	print_str_error(name);
	return (0);
}

static int	dup2_error(int fd)
{
	char	*fd_str;

	fd_str = ft_itoa(fd);
	if (!fd_str)
	{
		print_str_error("malloc");
		return (0);
	}
	print_str_error(fd_str);
	free(fd_str);
	close (fd);
	return (0);
}
