#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

static const char	digits[] = {'0', '1', '2', '3',\
								'4', '5', '6', '7',\
								'8', '9', 'a', 'b',\
								'c', 'd', 'e', 'f'};

typedef struct	s_wdp
{
	int	w;
	int	p;
	int	d;
}				t_wdp;

static size_t	ft_strlen(const char *s);

static void		ft_uitoa(char *s, unsigned int n);

static void		ft_itoa(char *s, int n);

static int		handle_s(t_wdp wdp, va_list *ap);

static int		handle_x(t_wdp wdp, va_list *ap);

static int		handle_d(t_wdp wdp, va_list *ap);

int	ft_printf(const char *fmt, ...)
{
	int		count;
	va_list	ap;
	t_wdp	wdp;
	
	va_start(ap, fmt);
	count = 0;
	while (*fmt)
	{
		wdp.w = 0;
		wdp.d = 0;
		wdp.p = 0;
		if (*fmt == '%')
		{
			++fmt;
			while ('0' <= *fmt && *fmt <= '9')
			{
				wdp.w *= 10;
				wdp.w += *fmt - '0';
				++fmt;
			}
			if (*fmt == '.')
			{
				wdp.d = 1;
				++fmt;
				while ('0' <= *fmt && *fmt <= '9')
				{
					wdp.p *= 10;
					wdp.p += *fmt - '0';
					++fmt;
				}
			}
			if (*fmt == 's')
				count += handle_s(wdp, &ap);
			else if (*fmt == 'd')
				count += handle_d(wdp, &ap);
			else if (*fmt == 'x')
				count += handle_x(wdp, &ap);
			else
				return(-1);
		}
		else
		{
			write(STDOUT_FILENO, fmt, 1);
			++count;
		}
		++fmt;
	}
	va_end(ap);
	return (count);
}

static int		handle_s(t_wdp wdp, va_list *ap)
{
	int		len;
	char	*s;
	int		count;

	count = 0;
	s = (char *) va_arg(*ap, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (wdp.d && wdp.p < len)
		len = wdp.p;
	wdp.w -= len;
	while (wdp.w-- > 0)
	{
		write(STDOUT_FILENO, " ", 1);
		++count;
	}
	if (wdp.d && wdp.p < len)
		len -= wdp.p;
	write(STDOUT_FILENO, s, len);
	count += len;
	return (count);
}

static int		handle_x(t_wdp wdp, va_list *ap)
{
	char			s[20];
	int				len;
	int				count;
	unsigned int	n;

	count = 0;
	s[0] = '\0';
	n = va_arg(*ap, unsigned int);
	ft_uitoa(s, n);
	if (n == 0 && wdp.d)
		s[0] = '\0';
	len = ft_strlen(s);
	if (wdp.d && wdp.p > len)
		wdp.w -= wdp.p;
	else
		wdp.w -= len;
	while (wdp.w-- > 0)
	{
		write(STDOUT_FILENO, " ", 1);
		++count;
	}
	if (wdp.d && wdp.p > len)
	{
		wdp.p -= len;
		while (wdp.p-- > 0)
		{
			write(STDOUT_FILENO, "0", 1);
			++count;
		}
	}
	write(STDOUT_FILENO, s, len);
	count += len;
	return (count);	
}

static int	handle_d(t_wdp wdp, va_list *ap)
{
	int		len;
	int		n;
	char	s[20];
	int		count;
	
	s[0] = '\0';
	n = (int) va_arg(*ap, int);
	count = 0;
	ft_itoa(s, n);
	if (wdp.d && n == 0)
		s[0] = '\0';
	len = ft_strlen(s);
	if (n < 0)
		--len;
	if (wdp.d && wdp.p > len)
		wdp.w -= wdp.p;
	else
		wdp.w -= len;
	if (n < 0)
		--wdp.w;
	while (wdp.w-- > 0)
	{
		write(STDOUT_FILENO, " ", 1);
		++count;
	}
	if (n < 0)
	{
		write(STDOUT_FILENO, s, 1);
		++count;
	}
	if (wdp.d && wdp.p > len)
	{
		wdp.p -= len;
		while (wdp.p-- > 0)
		{
			write(STDOUT_FILENO, "0", 1);
			++count;
		}
	}
	if (n < 0)
		write(STDOUT_FILENO, s + 1, len);
	else
		write(STDOUT_FILENO, s, len);
	count += len;
	return (count);
}

static size_t	ft_strlen(const char *s)
{
	const char	*str;

	str = s;
	while (*s)
		++s;
	return (s - str);
}

static void	ft_itoa(char *s, int n)
{
	int		num;
	int		k;
	int		rem;

	num = n;
	k = 0;
	if (n <= 0)
		++k;
	while (num)
	{
		++k;
		num /= 10;
	}
	s[k] = '\0';
	num = n;
	while (num)
	{
		rem = num % 10;
		if (rem < 0)
			rem = -rem;
		s[--k] = rem + '0';
		num /= 10;
	}
	if (n < 0)
		s[0] = '-';
	else if (n == 0)
		s[0] = '0';
}

static void		ft_uitoa(char *s, unsigned int n)
{
	unsigned int	num;
	int				k;

	num = n;
	k = 0;
	if (n == 0)
		++k;
	while (num)
	{
		++k;
		num /= 16;
	}
	s[k] = '\0';
	num = n;
	while (n)
	{
		s[--k] = digits[n % 16];
		n /= 16;
	}
	if (num == 0)
		s[0] = '0';
}
