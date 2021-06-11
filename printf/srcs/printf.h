/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:38:28 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/11 19:30:23 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# define BUFFER_SIZE 1024

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_fws
{
	unsigned char	zero;
	unsigned char	dash;
	unsigned char	dot;
	int				width;
	int				prec;
}				t_fws;

int		ft_max(int a, int b);

void	*ft_realloc(void *mptr, size_t size, size_t memsize);

int		ft_is_conversion_type(char c);

char	*buf_init(void);

char	*buf_add(const char *str, int k);

int		buf_output(void);

int		buf_error(void);

char	*ft_parse(t_fws *fws, const char *fmt, va_list *ap);

char	*ft_fmt_handle(t_fws *fws, const char *fmt, va_list *ap);

char	*ft_d_handle(t_fws *fws, const char *fmt, va_list *ap);

char	*ft_u_handle(t_fws *fws, const char *fmt, va_list *ap);

char	*ft_x_handle(t_fws *fws, const char *fmt, va_list *ap);

char	*ft_xx_handle(t_fws *fws, const char *fmt, va_list *ap);

char	*ft_p_handle(t_fws *fws, const char *fmt, va_list *ap);

char	*ft_utoa_base(unsigned int n, unsigned int base);

char	*ft_ultoa_base(unsigned long n, unsigned int base);

#endif
