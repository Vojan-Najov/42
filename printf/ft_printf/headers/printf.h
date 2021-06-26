/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:15:25 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/26 16:35:12 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# define BUFFER_SIZE 1024
# define H_SIZE 0b00000001
# define HH_SIZE 0b00000010
# define L_SIZE 0b00000100
# define LL_SIZE 0b00001000
# define F_DASH 0b00000001
# define F_ZERO 0b00000010
# define F_DOT 0b00000100
# define F_HASH 0b00001000
# define F_PLUS 0b00010000
# define F_SPACE 0b00100000
# define FTP_ERROR -1
# define FTP_OK 1
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include <wchar.h>
# define BI_BASE 1000000000L
# define BI_SIZE 36
# define BI_DIGIT 9
# define EXP_OFFSET 1023
# define MANT_SIZE 52
# define MANT_REM 12
# define IMPLICIT_UNIT 0x10000000000000L
# define SIGN_OFFSET 63
# define MANT_BITS 0xFFFFFFFFFFFFFL
# define EXP_BITS 0x7FF

typedef struct s_fws
{
	unsigned char	dash;
	unsigned char	zero;
	unsigned char	dot;
	unsigned char	hash;
	unsigned char	plus;
	unsigned char	space;
	unsigned char	size;
	int				width;
	int				prec;
}				t_fws;

int				ft_printf(const char *fmt, ...);

char			*buf_init(void);

char			*buf_add(const char *str, int k);

int				buf_output(int flag);

int				buf_count(void);

char			*ft_parse(t_fws *fws, const char *fmt, va_list *ap);

char			*ft_handle_fmt(t_fws *fws, const char *fmt, va_list *ap);

char			*ft_handle_perc(t_fws *fws, const char *fmt);

char			*ft_handle_c(t_fws *fws, const char *fmt, va_list *ap);

char			*ft_handle_s(t_fws *fws, const char *fmt, va_list *ap);

char			*ft_handle_p(t_fws *fws, const char *fmt, va_list *ap);

char			*ft_handle_u(t_fws *fws, const char *fmt, va_list *ap);

char			*ft_handle_o(t_fws *fws, const char *fmt, va_list *ap);

char			*ft_handle_x(t_fws *fws, const char *fmt, va_list *ap);

char			*ft_handle_xx(t_fws *fws, const char *fmt, va_list *ap);

char			*ft_handle_d(t_fws *fws, const char *fmt, va_list *ap);

char			*ft_handle_f(t_fws *fws, const char *fmt, va_list *ap);

void			ft_handle_f_without_dash(t_fws *fws, char *ip, char *fp);

char			*ft_handle_n(t_fws *fws, const char *fmt, va_list *ap);

char			*ft_utoa_base(unsigned int n, unsigned int base);

char			*ft_lltoa(long long n);

char			*ft_ultoa_base(unsigned long n, unsigned int base);

int				ft_max(int a, int b);

void			*ft_realloc(void *mptr, size_t size, size_t memsize);

int				ft_is_conversion_type(char c);

unsigned long	ft_degree_of_two(int exp);

int				ft_dftoa(double d, int prec, char **ip, char **fp);

char			*ft_intpart_to_ascii(int exp, unsigned long mant);

char			*ft_factpart_to_ascii(int exp, unsigned long mant, \
								int prec, int *carry);

void			ft_encode_utf8(int n);

#endif
