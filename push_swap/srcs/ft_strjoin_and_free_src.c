/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_and_free_src.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:20:31 by ccartman          #+#    #+#             */
/*   Updated: 2021/08/17 13:20:37 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_strjoin_and_free_src(char **src, const char *part)
{
	char	*tmp;

	tmp = *src;
	*src = ft_strjoin(tmp, part);
	free(tmp);
}
