/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:48:52 by jjoan             #+#    #+#             */
/*   Updated: 2022/03/10 18:54:20 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_list.h"

t_obj_lst	**get_first_objlst_adress(void)
{
	static t_obj_lst	*figure;

	return (&figure);
}

t_obj_lst	*get_first_objlst(void)
{
	t_obj_lst	**figure;

	figure = get_first_objlst_adress();
	return (*figure);
}
