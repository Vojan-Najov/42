/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_words.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:36:19 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/11 19:36:21 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	expansion_words(t_list **lst)
{
	t_list	*list_ptr;
	char	**word_ptr;

	list_ptr = *lst;
	while (list_ptr)
	{
		if (list_ptr->flag == ARGUMENT)
		{
			word_ptr = &list_ptr->word;
			if (!expansion_word(word_ptr))
				return (malloc_list_error(lst));
		}
		list_ptr = list_ptr->next;
	}
	return (PARSE_SUCCESS);
}
