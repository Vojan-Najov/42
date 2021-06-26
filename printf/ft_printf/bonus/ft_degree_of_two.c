/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_degree_of_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 12:11:38 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/23 12:12:50 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned long	ft_degree_of_two(int exp)
{
	unsigned long	res;

	res = 1;
	if (exp < 0)
		res = 0;
	else
		while (exp-- > 0)
			res *= 2;
	return (res);
}
