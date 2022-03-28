/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objlst_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 22:10:35 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/10 18:54:27 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_list.h"
#include "minirt_types.h"

int	ft_objlst_size(void)
{
	int			size;
	t_obj_lst	*objlst;

	objlst = get_first_objlst();
	size = 0;
	while (objlst)
	{
		objlst = objlst->next;
		++size;
	}
	return (size);
}
