/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objlst_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 21:00:21 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/10 18:59:03 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_list.h"
#include "minirt_types.h"
#include <stdlib.h>

t_obj_lst	*ft_objlst_new(t_obj *obj)
{
	t_obj_lst	*objnew;

	objnew = (t_obj_lst *) malloc(sizeof(t_obj_lst));
	if (objnew)
	{
		objnew->obj = obj;
		objnew->next = NULL;
	}
	return (objnew);
}
