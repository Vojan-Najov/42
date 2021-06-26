/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:08:10 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/10 18:39:15 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	*ft_realloc(void *mptr, size_t size, size_t memsize)
{
	void	*ret;

	ret = malloc(size);
	if (ret)
		ft_memcpy(ret, mptr, memsize);
	free(mptr);
	return (ret);
}
