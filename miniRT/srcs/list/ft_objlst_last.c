/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objlst_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 22:50:08 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/10 18:54:34 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_list.h"
#include "minirt_types.h"

t_obj_lst	*ft_objlast(void)
{
	t_obj_lst	*objlst;

	objlst = get_first_objlst();
	if (objlst)
		while (objlst->next)
			objlst = objlst->next;
	return (objlst);
}
