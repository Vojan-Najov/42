/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objlst_iter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 22:07:37 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/10 18:54:42 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_list.h"
#include "minirt_types.h"

void	ft_objiter(void (*f)(void *))
{
	t_obj_lst	*objlst;

	objlst = get_first_objlst();
	while (objlst)
	{
		(*f)(objlst->obj);
		objlst = objlst->next;
	}
}
