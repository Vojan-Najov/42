/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:29:38 by ccartman          #+#    #+#             */
/*   Updated: 2021/12/31 15:22:46 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(int c);

int	ft_atoi(const char *str)
	{
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	while (ft_isspace((unsigned char)*str))
		++str;
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	else if (*str == '+')
		++str;
	while ('0' <= *str && *str <= '9')
	{
		result = 10 * result + (*str - '0');
		++str;
	}
	return (result * sign);
}

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' \
															|| c == ' ')
		return (c);
	else
		return (0);
}
