/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:38:08 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/11 20:05:05 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	init_command_redirect(t_command *command, t_list **lst);

static int	init_redirect(t_redirect **redirect, t_list **lst);

static int	init_command_argv(t_command *command, t_list **lst);

static void	init_arg(char **arg, t_list **lst);

int	init_command(t_command **command, t_list **lst)
{
	*command = (t_command *) malloc(sizeof(t_command));
	if (!*command)
		return (PARSE_ERROR);
	if (!init_command_redirect(*command, lst))
		return (PARSE_ERROR);
	if (!init_command_argv(*command, lst))
		return (PARSE_ERROR);
	return (PARSE_SUCCESS);
}

static int	init_command_redirect(t_command *command, t_list **lst)
{
	size_t	i;
	size_t	n;

	n = count_redirects(*lst);
	command->redirect = (t_redirect **) \
							malloc(sizeof(t_redirect *) * (n + 1));
	if (!command->redirect)
	{
		free(command);
		return (PARSE_ERROR);
	}
	command->redirect[n] = NULL;
	i = -1;
	while (++i < n)
	{
		if (!init_redirect(command->redirect + i, lst))
		{
			free_redirect(command->redirect);
			free(command);
			return (PARSE_ERROR);
		}
	}
	return (PARSE_SUCCESS);
}

static int	init_redirect(t_redirect **redirect, t_list **lst)
{
	t_list	*tmp;

	*redirect = (t_redirect *) malloc(sizeof(t_redirect));
	if (!*redirect)
	{
		*redirect = NULL;
		return (PARSE_ERROR);
	}
	while (*lst)
	{
		if ((*lst)->flag & REDIRECT)
			break ;
		lst = &(*lst)->next;
	}
	(*redirect)->type = (*lst)->flag ^ REDIRECT;
	(*redirect)->fd = get_fd(*lst);
	tmp = *lst;
	*lst = (*lst)->next;
	free(tmp->word);
	free(tmp);
	(*redirect)->name = (*lst)->word;
	tmp = *lst;
	*lst = (*lst)->next;
	free(tmp);
	return (PARSE_SUCCESS);
}

static int	init_command_argv(t_command *command, t_list **lst)
{
	size_t	n;
	size_t	i;

	n = count_args(*lst);
	command->argv = (char **) malloc(sizeof(char *) * (n + 1));
	if (!command->argv)
	{
		free_redirect(command->redirect);
		free(command);
		return (PARSE_ERROR);
	}
	command->argv[n] = NULL;
	i = -1;
	while (++i < n)
		init_arg(command->argv + i, lst);
	return (PARSE_SUCCESS);
}

static void	init_arg(char **arg, t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		if ((*lst)->flag & ARGUMENT)
			break ;
		lst = &(*lst)->next;
	}
	*arg = (*lst)->word;
	tmp = *lst;
	*lst = (*lst)->next;
	free(tmp);
}
