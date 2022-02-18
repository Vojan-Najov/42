/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:35:27 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/11 19:35:32 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_list	*check_token(t_list *lst);

static int		check_pipeline_token(t_list *lst, int flag_prev);

static int		check_redirect_token(t_list *lst, int flag_prev);

static int		check_tokens_error(t_list **lst, char *token);

int	check_tokens(t_list **lst_ptr)
{
	int		i;
	t_list	*lst;

	lst = *lst_ptr;
	lst = check_token(lst);
	if (lst)
	{
		i = 0;
		if (!ft_isdigit(*lst->word))
			return (check_tokens_error(lst_ptr, lst->word));
		while (ft_isdigit(lst->word[i]))
			++i;
		lst->word[i] = '\0';
		return (check_tokens_error(lst_ptr, lst->word));
	}
	return (PARSE_SUCCESS);
}

static t_list	*check_token(t_list *lst)
{
	int	flag_prev;

	flag_prev = 0;
	while (lst)
	{
		if (!check_pipeline_token(lst, flag_prev))
			return (lst);
		if (!check_redirect_token(lst, flag_prev))
			return (lst);
		flag_prev = lst->flag;
		lst = lst->next;
	}
	return (NULL);
}

static int	check_pipeline_token(t_list *lst, int flag_prev)
{
	if (lst->flag != PIPELINE)
		return (1);
	if (flag_prev == PIPELINE)
		return (0);
	if (flag_prev & REDIRECT)
		return (0);
	if (flag_prev == 0)
		return (0);
	if (!lst->next)
		return (0);
	return (1);
}

static int	check_redirect_token(t_list *lst, int flag_prev)
{
	if (!(lst->flag & REDIRECT))
		return (1);
	if (flag_prev & REDIRECT)
		return (0);
	if (!lst->next)
		return (0);
	return (1);
}

static int	check_tokens_error(t_list **lst, char *token)
{
	write(STDERR_FILENO, g_token_err, sizeof(g_token_err) - 1);
	write(STDERR_FILENO, token, ft_strlen(token));
	write(STDERR_FILENO, "'\n", 2);
	ft_lstclear(lst, free);
	return (PARSE_ERROR);
}
