/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 13:20:01 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/05 14:58:47 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*copy;

	copy = (char *) malloc(sizeof(*copy) * (n + 1));
	if (copy)
	{
		ft_memcpy(copy, str, n);
		copy[n] = '\0';
	}
	return (copy);
}
