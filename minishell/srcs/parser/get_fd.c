/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:37:33 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/11 19:37:37 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	get_fd(t_list *lst)
{
	int	fd;

	if (ft_isdigit(lst->word[0]))
		fd = ft_atoi(lst->word);
	else if (lst->flag & (REDIRECT_INPUT | REDIRECT_HEREDOC))
		fd = 0;
	else if (lst->flag & (REDIRECT_OUTPUT | REDIRECT_APPEND))
		fd = 1;
	else
		fd = -1;
	return (fd);
}
