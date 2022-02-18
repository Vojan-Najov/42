/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pathname.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:38:22 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/17 18:55:42 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static int	check_stat(const char *name, int flag);

static char	*search_pathname(const char *name, char **path);

static char	*check_pathname(char **path, const char *name);

char	*get_pathname(const char *name)
{
	char	*pathname;
	char	**path;

	if (!*name)
	{
		print_cmd_error(name);
		exit(CMD_ERROR);
	}
	if (name[0] == '/' || !ft_strncmp(name, "./", 2) \
							|| !ft_strncmp(name, "../", 3))
	{
		if (check_stat(name, 0))
			return ((char *) name);
	}
	path = get_paths();
	pathname = search_pathname(name, path);
	free_str_tab(path);
	return (pathname);
}

static int	check_stat(const char *name, int flag)
{
	struct stat	buf;

	if (stat(name, &buf) == -1)
	{
		if (flag)
			name += 2;
		print_str_error(name);
		exit(CMD_ERROR);
	}
	if (buf.st_mode & S_IFDIR)
	{
		if (flag)
			name += 2;
		print_dir_error(name);
		exit(FILE_ERROR);
	}
	if (!(buf.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)))
	{
		if (flag)
			name += 2;
		print_str_error(name);
		exit(FILE_ERROR);
	}
	return (1);
}

static char	*search_pathname(const char *name, char **path)
{
	char	*pathname;

	if (!path)
	{
		pathname = ft_strjoin("./", name);
		if (!pathname)
		{
			print_str_error("malloc");
			exit(EXIT_FAILURE);
		}
		if (check_stat(pathname, 1))
			return (pathname);
	}
	pathname = check_pathname(path, name);
	return (pathname);
}

static char	*check_pathname(char **path, const char *name)
{
	size_t		i;
	char		*pathname;
	struct stat	buf;

	i = -1;
	pathname = NULL;
	while (path[++i])
	{
		pathname = ft_strjoin(path[i], name);
		if (!pathname)
		{
			print_str_error("malloc");
			exit(EXIT_FAILURE);
		}
		if (!stat(pathname, &buf) && !(buf.st_mode & S_IFDIR) && \
				(buf.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)))
			break ;
		free(pathname);
		pathname = NULL;
	}
	if (!pathname)
		print_cmd_error(name);
	return (pathname);
}
