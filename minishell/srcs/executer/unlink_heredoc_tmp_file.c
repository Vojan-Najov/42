/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink_heredoc_tmp_file.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:11:03 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/20 14:58:21 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	unlink_heredoc_tmp_file(t_command **cmd)
{
	size_t	i;
	size_t	j;
	char	*fn;

	i = -1;
	while (cmd[++i])
	{
		j = -1;
		while (cmd[i]->redirect[++j])
		{
			if (cmd[i]->redirect[j]->type & REDIRECT_HEREDOC)
			{
				fn = cmd[i]->redirect[j]->name;
				if (!ft_strncmp(fn, HRDC_TMPFILE, sizeof(HRDC_TMPFILE) - 1))
				{
					if (unlink(cmd[i]->redirect[j]->name) == -1)
						print_str_error(cmd[i]->redirect[j]->name);
				}
			}
		}
	}
	return (0);
}
