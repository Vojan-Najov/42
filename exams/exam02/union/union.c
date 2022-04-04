/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:34:42 by ccartman          #+#    #+#             */
/*   Updated: 2021/08/18 21:18:34 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define NL "\n"
#define STDOUT_FILLENO 1

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		flag;

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			j = 0;
			while (argv[1][i] != argv[1][j])
				++j;
			if (i == j)
				write(STDOUT_FILLENO, &argv[1][i], 1);
			++i;
		}
		i = 0;
		while (argv[2][i])
		{
			flag = 0;
			j = 0;
			while (argv[1][j])
			{
				if (argv[2][i] == argv[1][j])
				{
					flag = 1;
					break ;
				}
				++j;
			}
			if (!flag)
			{
				j = 0;
				while (argv[2][i] != argv[2][j])
					++j;
				if (i == j)
					write(STDOUT_FILLENO, &argv[2][i], 1);
			}
			++i;
		}
	}
	write(STDOUT_FILLENO, NL, 1);
	return (0);
}
