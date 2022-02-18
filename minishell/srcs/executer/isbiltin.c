/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isbiltin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:33:21 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/11 18:23:47 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include "builtin.h"

t_biltin_ptr	isbiltin(const char *name)
{
	if (!name)
		return (NULL);
	if (!ft_strcmp(name, "echo"))
		return (ft_echo);
	if (!ft_strcmp(name, "cd"))
		return (ft_cd);
	if (!ft_strcmp(name, "pwd"))
		return (ft_pwd);
	if (!ft_strcmp(name, "export"))
		return (ft_export);
	if (!ft_strcmp(name, "unset"))
		return (ft_unset);
	if (!ft_strcmp(name, "env"))
		return (ft_env);
	if (!ft_strcmp(name, "exit"))
		return (ft_exit);
	return (NULL);
}
