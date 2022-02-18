/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:33:16 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/11 19:33:19 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	malloc_and_fill_command(t_cmds *cmds, size_t n, t_list **lsts);

static void	init_cmds_error(t_list **lsts);

t_cmds	*init_cmds(t_list **lsts)
{
	t_cmds	*cmds;
	size_t	n;

	cmds = (t_cmds *) malloc(sizeof(t_cmds));
	if (!cmds)
	{
		init_cmds_error(lsts);
		return (NULL);
	}
	n = count_commands(lsts);
	if (n > 1)
		cmds->type = PIPELINE;
	else
		cmds->type = SIMPLE_COMMAND;
	if (!malloc_and_fill_command(cmds, n, lsts))
		return (NULL);
	free(lsts);
	return (cmds);
}

static int	malloc_and_fill_command(t_cmds *cmds, size_t n, t_list **lsts)
{
	cmds->command = (t_command **) malloc(sizeof(t_command) * (n + 1));
	if (!cmds->command)
	{
		init_cmds_error(lsts);
		return (PARSE_ERROR);
	}
	cmds->command[n] = NULL;
	n = 0;
	while (lsts[n])
	{
		if (!init_command(cmds->command + n, lsts + n))
		{
			cmds->command[n] = NULL;
			free_cmds(cmds);
			init_cmds_error(lsts);
			return (PARSE_ERROR);
		}
		++n;
	}
	return (PARSE_SUCCESS);
}

static void	init_cmds_error(t_list **lsts)
{
	size_t	i;
	char	*err;

	i = 0;
	while (lsts[i])
	{
		ft_lstclear(lsts + i, free);
		++i;
	}
	free(lsts);
	write(STDERR_FILENO, g_shell_name, sizeof(g_shell_name) - 1);
	err = strerror(errno);
	write(STDERR_FILENO, err, ft_strlen(err));
	write(STDERR_FILENO, "\n", 1);
}
