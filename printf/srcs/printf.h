/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:38:28 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/10 18:37:29 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include <stdio.h>

typedef struct	s_fws
{
	unsigned char	zero;
	unsigned char	dash;
	unsigned char	dot;
	int				width;
	int				prec;
}				t_fws;

void	*ft_realloc(void *mptr, size_t size, size_t memsize);

char	*buf_init();

char	*buf_add(const char *str, unsigned k);

int		buf_output();

int		buf_error();

char	*ft_parse(t_fws *fws, const char *fmt, va_list *ap);

char	*ft_fmt_handle(t_fws *fws, const char *fmt, va_list *ap);

int		ft_is_conversion_type(char c);

t_list	*ft_split_str_by_percentage(const char *fmt);

char	*ft_strndup(const char *str, size_t n);

char    *ft_utoa_base(unsigned n, unsigned base);

char    *ft_ultoa_base(unsigned long n, unsigned base);


#endif
