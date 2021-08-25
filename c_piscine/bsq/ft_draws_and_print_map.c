/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draws_and_print_map.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:53:30 by ccartman          #+#    #+#             */
/*   Updated: 2021/03/10 20:55:24 by malison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

unsigned int	*ft_read_map(int fd, t_desc *desc)
{
	unsigned int	*matrix;
	char			*buf;

	buf = 0;
	if (!(desc = ft_read_zero_line(fd, desc)))
		return (0);
	if (!(matrix = ft_read_first_line(fd, desc)))
		return (0);
	if (!(matrix = ft_read_other_lines(fd, desc, matrix, buf)))
		return (0);
	free(buf);
	return (matrix);
}

void			ft_draws_and_print_map(int fd)
{
	unsigned int	*matrix;
	t_desc			*desc;
	t_sq			*rez;

	matrix = NULL;
	if (!(desc = malloc(sizeof(t_desc))))
		write(2, "map error\n", 10);
	else if (!(matrix = ft_read_map(fd, desc)))
		write(2, "map error\n", 10);
	else
	{
		rez = ft_find_square(matrix, desc->lines, desc->rows);
		ft_output(desc, rez, matrix);
	}
	free(matrix);
	free(desc);
}
