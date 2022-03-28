/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objlst_add_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 21:16:47 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/11 22:52:26 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_list.h"
#include "minirt_types.h"

void	ft_objlst_add_front(t_obj_lst *new)
{
	t_obj_lst	**objlst;

	objlst = get_first_objlst_adress();
	if (*objlst)
		new->next = *objlst;
	*objlst = new;
	return ;
}
