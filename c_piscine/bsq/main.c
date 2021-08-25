/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:29:16 by ccartman          #+#    #+#             */
/*   Updated: 2021/03/10 21:37:32 by malison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		main(int argc, char **argv)
{
	int		n;
	int		fd;

	if (argc == 1)
		ft_draws_and_print_map(0);
	else
	{
		n = 0;
		while (++n < argc)
		{
			fd = open(argv[n], O_RDONLY);
			if (fd == -1)
			{
				write(2, "map error\n", 10);
				continue ;
			}
			ft_draws_and_print_map(fd);
			if (argc > 2)
				write(1, "\n", 1);
			close(fd);
		}
	}
	return (0);
}
