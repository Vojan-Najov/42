#include "fractol.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (c);
	else
		return (0);
}

int	check_float(const char *str)
{
	if (*str == '-' || *str == '+')
		++str;
	while (ft_isdigit(*str))
		++str;
	if (*str == '.')
		++str;
	else if (*str == '\0')
		return (1);
	else
		return (0);
	while (ft_isdigit(*str))
		++str;
	if (*str == '\0')
		return (1);
	else
		return (0);
}

double	ft_atof(const char *str)
{
	int		sign;
	int		count;
	double	d;

	d = 0;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str != '.')
	{
		d = 10 * d + (*str - '0');
		++str;
	}
	if (*str == '.')
		++str;
	count = 0;
	while (*str)
	{
		--count;
		d += (*str - '0') * pow(10.0, (double) count);
		++str;
	}
	return (sign * d);
}

///
/*
int	main(int argc, char **argv)
{
	double d;

	if (argc != 2)
		return (1);
	if (!check_float(argv[1]))
	{
		printf("not a float\n");
		return (0);
	}
	printf("float \n");
	d = ft_atof(argv[1]);
	printf("d = %lf\n", d);
	return (0);
}
*/
