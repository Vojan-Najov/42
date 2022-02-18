/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:46:09 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/17 15:25:46 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static int	search_path(char **envp);

static char	**add_slash(char **paths);

char	**get_paths(void)
{
	int		i;
	char	**envp;
	char	**paths;

	envp = get_envp();
	i = search_path(envp);
	if (i == -1)
	{
		return (NULL);
	}
	paths = ft_split(&envp[i][5], ':');
	if (!paths)
	{
		print_str_error("malloc");
		exit(EXIT_FAILURE);
	}
	paths = add_slash(paths);
	return (paths);
}

static int	search_path(char **envp)
{
	char	*path;
	size_t	len;
	int		i;

	i = 0;
	path = "PATH=";
	len = ft_strlen(path);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], path, len) == 0)
			return (i);
		++i;
	}
	return (-1);
}

static char	**add_slash(char **paths)
{
	int		i;
	char	*tmp;

	i = 0;
	while (paths[i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(paths[i], "/");
		if (!paths[i])
		{
			free_str_tab(paths);
			print_str_error("malloc");
			exit(EXIT_FAILURE);
		}
		free(tmp);
		++i;
	}
	return (paths);
}
