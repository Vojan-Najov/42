/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:39:31 by ccartman          #+#    #+#             */
/*   Updated: 2021/03/10 21:17:40 by malison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_desc			*ft_check_map_info(char *str, t_desc *desc)
{
	int				i;
	unsigned int	map_size;

	i = ft_strlen(str);
	if ((map_size = ft_atoi(str)) && ft_check_symbs(str[i - 3], str[i - 2],\
																str[i - 1]))
	{
		desc->lines = map_size;
		desc->empty = str[i - 3];
		desc->obstacle = str[i - 2];
		desc->full = str[i - 1];
	}
	else
		return (0);
	return (desc);
}

t_desc			*ft_read_zero_line(int fd, t_desc *desc)
{
	char		*buf;
	int			i;
	int			ret;
	int			size;

	i = -1;
	size = 128;
	if (!(buf = malloc(sizeof(char) * size)))
		return (0);
	while ((ret = read(fd, &buf[++i], 1)) && (buf[i] != '\n'))
	{
		if (ret == -1)
			break ;
		if (i == size - 1)
			buf = ft_dupx(buf, &size);
	}
	if (buf[i] != '\n' || ret == -1)
	{
		free(buf);
		return (0);
	}
	buf[i] = '\0';
	desc = ft_check_map_info(buf, desc);
	free(buf);
	return (desc);
}

unsigned int	*ft_check_first_line(char *str, t_desc *desc)
{
	int				n;
	char			obst;
	char			empt;
	unsigned int	*matrix;

	empt = desc->empty;
	obst = desc->obstacle;
	n = -1;
	while (str[++n])
	{
		if ((str[n] != empt) && (str[n] != obst))
			return (0);
	}
	desc->rows = n;
	if (!(matrix = malloc(sizeof(int) * desc->lines * n)))
		return (0);
	n = -1;
	while (str[++n])
		if (str[n] == empt)
			matrix[n] = 1;
		else if (str[n] == obst)
			matrix[n] = 0;
	free(str);
	return (matrix);
}

unsigned int	*ft_read_first_line(int fd, t_desc *desc)
{
	char			*buf;
	unsigned int	*matrix;
	int				i;
	int				ret;
	int				size;

	i = -1;
	size = 128;
	if (!(buf = malloc(sizeof(char) * size)))
		return (0);
	while ((ret = read(fd, &buf[++i], 1)) && (buf[i] != '\n'))
	{
		if (ret == -1)
			break ;
		if (i == size - 1)
			buf = ft_dupx(buf, &size);
	}
	if (buf[i] != '\n' || ret == -1)
	{
		free(buf);
		return (0);
	}
	buf[i] = '\0';
	matrix = ft_check_first_line(buf, desc);
	return (matrix);
}

unsigned int	*ft_read_other_lines(int fd, t_desc *desc,\
				unsigned int *matrix, char *buf)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if ((buf = malloc(sizeof(char) * (desc->rows + 1))))
		while (++i < desc->lines)
		{
			j = read(fd, buf, desc->rows + 1);
			if (j != desc->rows + 1)
				return (0);
			j = -1;
			while (++j < desc->rows)
				if (buf[j] != desc->obstacle && buf[j] != desc->empty)
					return (0);
				else if (buf[j] == desc->obstacle)
					matrix[i * desc->rows + j] = 0;
				else if (buf[j] == desc->empty)
					matrix[i * desc->rows + j] = 1;
		}
	if (read(fd, buf, 1) != 0)
		return (0);
	free(buf);
	return (matrix);
}
