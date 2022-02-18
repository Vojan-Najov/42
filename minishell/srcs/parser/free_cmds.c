/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:36:42 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/11 19:36:44 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	free_argv(char **argv);

void	free_cmds(t_cmds *cmds)
{
	size_t		i;
	t_command	**cmd;

	i = -1;
	cmd = cmds->command;
	while (cmd[++i])
	{
		free_redirect(cmd[i]->redirect);
		free_argv(cmd[i]->argv);
		free(cmd[i]);
	}
	free(cmd);
	free(cmds);
}

void	free_redirect(t_redirect **rdr)
{
	size_t	i;

	i = -1;
	while (rdr[++i])
	{
		free(rdr[i]->name);
		free(rdr[i]);
	}
	free(rdr);
}

static void	free_argv(char **argv)
{
	size_t	i;

	i = -1;
	while (argv[++i])
	{
		free(argv[i]);
	}
	free(argv);
}
