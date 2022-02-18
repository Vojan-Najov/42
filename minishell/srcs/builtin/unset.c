/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:46:25 by jjoan             #+#    #+#             */
/*   Updated: 2022/02/17 11:51:58 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_envp.h"

int	unset_one(const char *s)
{
	char	*unset;
	int		ret;

	unset = ft_getenv_with_name(s);
	if (!unset)
		return (0);
	ret = change_envp(-1, unset);
	return (ret);
}

int	ft_unset(char **s)
{
	size_t	len;
	size_t	i;
	int		rez;

	len = mas_size(s);
	i = 0;
	rez = 0;
	while (i < len)
		rez = unset_one(s[i++]);
	return (rez);
}
