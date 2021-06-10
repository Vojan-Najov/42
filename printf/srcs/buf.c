/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:29:13 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/11 00:15:16 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "printf.h"

static char *buf;
static char *ptr;
static int  bufsize;

char    *buf_init()
{
    bufsize = 2 * 1024;
    buf = (char *)malloc(sizeof(*buf) * bufsize);
    ptr = buf;
    return (buf);
}

char    *buf_realloc()
{
    size_t  n;

    n = ptr - buf;
    bufsize += 2 * 1024;
    buf =  (char *) ft_realloc(buf, bufsize, n);
    ptr = buf + n;
    return (buf);
}

char    *buf_add(const char *str, unsigned int k)
{
	if (!buf)
		return (NULL);
    if (ptr + k > buf + bufsize)
        buf_realloc();
    if (!buf)
        return (NULL);
    while (k-- > 0)
        *ptr++ = *str++;
    return (ptr);
}

int     buf_output()
{
	size_t  n;

	if (!buf)
		return (-1);
	n = ptr - buf;
	write(1, buf, n);
	free(buf);
	buf = NULL;
	return ((int) n);
}

int	buf_error()
{
	free(buf);
	buf = NULL;
	return (-1);
}
