/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objlst_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:05:42 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/16 19:13:50 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_list.h"
#include "minirt_types.h"
#include <stdlib.h>

void	ft_objlst_clear(void (*del)(t_obj *))
{
	t_obj_lst	**objlst;
	t_obj_lst	*ptr;

	objlst = get_first_objlst_adress();
	while (*objlst)
	{
		ptr = (*objlst)->next;
		(*del)((*objlst)->obj);
		(*objlst)->next = NULL;
		free(*objlst);
		*objlst = ptr;
	}
}
