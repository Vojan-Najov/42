/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 23:03:13 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/15 20:17:16 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <strings.h>

static char	*g_buf;
static char	*g_ptr;
static int	g_bufsize;

char	*buf_init(void)
{
	g_bufsize = BUFFER_SIZE;
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
	while (k-- > 0)
	{
		memset(g_ptr, *str, 1);
		g_ptr++;
	   	str++;
	}
	return (g_ptr);
}

int	buf_output(void)
{
	size_t	n;

	if (!g_buf)
		return (-1);
	n = g_ptr - g_buf;
	write(1, g_buf, n);
	free(g_buf);
	g_buf = NULL;
	return ((int) n);
}

int	buf_error(void)
{
	buf_output();
	return (-1);
}
