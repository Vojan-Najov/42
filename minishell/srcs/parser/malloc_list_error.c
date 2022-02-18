/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_list_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:38:51 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/11 19:38:54 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	malloc_list_error(t_list **lst)
{
	char	*err;

	write(STDERR_FILENO, g_shell_name, sizeof(g_shell_name) - 1);
	err = strerror(errno);
	write(STDERR_FILENO, err, ft_strlen(err));
	write(STDERR_FILENO, "\n", 1);
	ft_lstclear(lst, free);
	return (PARSE_ERROR);
}
