/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:29:55 by jjoan             #+#    #+#             */
/*   Updated: 2022/03/25 17:57:10 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "init_struct.h"
#include "libft.h"
#include "utils.h"
#include "parser.h"
#include <fcntl.h>

int	get_type_of_figure(char *str)
{
	if (!ft_strcmp(str, "sp"))
		return (SPHERE);
	else if (!ft_strcmp(str, "pl"))
		return (PLANE);
	else if (!ft_strcmp(str, "cy"))
		return (CYLINDRE);
	else
		print_err(WRONG_IDENT);
	return (0);
}

void	analise_line(char *line)
{
	char	**tab;

	if (!ft_isprint(*line))
		return ;
	tab = ft_split(line, ' ');
	if (!tab)
		print_err(MALLOC);
	else if (!ft_strcmp(tab[0], "A"))
		add_ambient(tab + 1);
	else if (!ft_strcmp(tab[0], "C"))
		add_camera(tab + 1);
	else if (!ft_strcmp(tab[0], "L"))
		add_light(tab + 1);
	else if (!ft_strcmp(tab[0], "sp"))
		add_figure(tab);
	else if (!ft_strcmp(tab[0], "pl"))
		add_figure(tab);
	else if (!ft_strcmp(tab[0], "cy"))
		add_figure(tab);
	else
		print_err(WRONG_IDENT);
	free_str_tab(tab);
}

static void	check_name(const char *file_name)
{
	size_t	len;

	len = ft_strlen(file_name);
	if (len < 3)
		print_err(WRONG_NAME);
	len -= 3;
	if (ft_strcmp(file_name + len, ".rt"))
		print_err(WRONG_NAME);
}

void	parse_file(char *file_name)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	check_name(file_name);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		print_err_open(file_name);
	while (get_next_line(fd, &line) > 0)
	{
		analise_line(line);
		free(line);
	}
	free(line);
}
