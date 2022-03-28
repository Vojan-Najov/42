/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objlst_add_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 23:00:51 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/10 20:18:54 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_list.h"
#include "minirt_types.h"

void	ft_objlst_add_back(t_obj_lst *new)
{
	t_obj_lst	*ptr;
	t_obj_lst	**objlst;

	objlst = get_first_objlst_adress();
	if (*objlst)
	{
		ptr = get_first_objlst();
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
	else
		*objlst = new;
	return ;
}
