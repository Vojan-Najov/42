/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istoken.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:37:12 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/11 19:37:13 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_istoken(const char *str, int flag)
{
	int	i;

	i = 0;
	if (str[i] == '|')
		return (1);
	if (str[i] != '<' && str[i] != '>' && flag)
		return (0);
	while (ft_isdigit(str[i]))
		++i;
	if (str[i] == '<' && str[i + 1] == '<')
		return (i + 2);
	if (str[i] == '<')
		return (i + 1);
	if (str[i] == '>' && str[i + 1] == '>')
		return (i + 2);
	if (str[i] == '>')
		return (i + 1);
	return (0);
}
