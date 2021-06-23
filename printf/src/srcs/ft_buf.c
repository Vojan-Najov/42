/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 23:03:13 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/19 23:13:05 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <strings.h>

static char	*g_buf;
static char	*g_ptr;
static int	g_bufsize;
static int	g_count;

char	*buf_init(void)
{
	g_bufsize = BUFFER_SIZE;
	g_count = 0;
	g_buf = (char *)malloc(sizeof(*g_buf) * g_bufsize);
	g_ptr = g_buf;
	return (g_buf);
}

static char	*buf_realloc(void)
{
	size_t	n;

	n = g_ptr - g_buf;
	g_bufsize += BUFFER_SIZE;
	g_buf = (char *) ft_realloc(g_buf, g_bufsize, n);
	g_ptr = g_buf + n;
	return (g_buf);
}

char	*buf_add(const char *str, int k)
{
	if (!g_buf)
		return (NULL);
	if (g_ptr + k > g_buf + g_bufsize)
		buf_realloc();
	if (!g_buf)
		return (NULL);
	if (k > 1 && ((*str & 0b11000000) == 0b11000000))
		++g_count;
	else
		g_count += k;
	while (k-- > 0)
	{
		memset(g_ptr, *str, 1);
		g_ptr++;
		str++;
	}
	return (g_ptr);
}

int	buf_output(int flag)
{
	size_t	n;

	if (!g_buf)
		return (-1);
	n = g_ptr - g_buf;
	write(1, g_buf, n);
	free(g_buf);
	g_buf = NULL;
	if (flag == F_ERROR)
		return (-1);
	return (g_count);
}

int	buf_count(void)
{
	return (g_count);
}