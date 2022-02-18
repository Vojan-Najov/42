/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink_heredoc_tmp_file.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:11:03 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/14 21:24:50 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	unlink_heredoc_tmp_file(t_command **cmd)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (cmd[++i])
	{
		j = -1;
		while (cmd[i]->redirect[++j])
		{
			if (cmd[i]->redirect[j]->type & REDIRECT_HEREDOC)
			{
				if (unlink(cmd[i]->redirect[j]->name) == -1)
					print_str_error(cmd[i]->redirect[j]->name);
			}
		}
	}
	return (0);
}
