/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 22:09:27 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/16 19:14:06 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_LIST_H
# define OBJ_LIST_H

# include "minirt_types.h"
# include "parse_struct.h"

typedef struct s_obj_lst
{
	t_obj				*obj;
	struct s_obj_lst	*next;
}				t_obj_lst;

t_light		*get_light(void);

t_camera	*get_camera(void);

t_ambient	*get_ambient(void);

t_obj_lst	*get_first_objlst(void);

t_obj_lst	**get_first_objlst_adress(void);

t_obj_lst	*ft_objlst_new(t_obj *obj);

void		ft_objlst_add_front(t_obj_lst *new);

int			ft_objlst_size(void);

t_obj_lst	*ft_objlst_last(void);

void		ft_objlst_add_back(t_obj_lst *new);

void		ft_objlst_clear(void (*del)(t_obj *));

void		ft_objlst_iter(void (*f)(void *));

#endif
