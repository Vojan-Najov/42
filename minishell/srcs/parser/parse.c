/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:39:27 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/14 19:21:56 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_cmds	*parse(const char *str)
{
	t_list	*lst;
	t_list	**lsts;
	t_cmds	*cmds;

	if (preparse(str) != PREPARSE_SUCCESS)
		return (NULL);
	lst = NULL;
	if (!split_into_words(str, &lst))
		return (NULL);
	if (!split_into_tokens(&lst))
		return (NULL);
	set_words_flags(lst);
	if (!check_tokens(&lst))
		return (NULL);
	if (!expansion_words(&lst))
		return (NULL);
	lsts = split_into_commands(&lst);
	if (!lsts)
		return (NULL);
	cmds = init_cmds(lsts);
	if (!cmds)
		return (NULL);
	return (cmds);
}
