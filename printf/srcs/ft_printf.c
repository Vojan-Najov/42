/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:41:37 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/11 00:14:11 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

static char    *buf_add_fmt(const char *fmt, va_list *ap);

int ft_printf(const char *fmt, ...)
{
    va_list ap;

    if (!fmt)
    {
        ft_printf("null\n");
        return (-1);
    }
    buf_init();
    va_start(ap, fmt);
    while (*fmt)
    {
        if (*fmt != '%')
			buf_add(fmt, 1);
        else
		{
			fmt = buf_add_fmt(++fmt, &ap);
			if (!fmt)
				return (buf_error());
		}
        ++fmt;
    }
    va_end(ap);
    return (buf_output());
}

static char    *buf_add_fmt(const char *fmt, va_list *ap)
{
	t_fws	*fws;

	if (*fmt == '%')
		return (buf_add(fmt, 1));
	fws = (t_fws *) malloc(sizeof(*fws));
	if (!fws)
		return (NULL);
	fmt = ft_parse(fws, fmt, ap);
	if (!fmt)
		return (NULL);
	fmt = ft_fmt_handle(fws, fmt, ap);
	free(fws);
	return ((char *) fmt);
}

///////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ft_printf(argv[1]);
        ft_printf("\n");
    }
    else if (argc == 1)
    {
        ft_printf("hello %c 123\n", 'D');
		ft_printf("hello %19c 123\n", 'D');
		ft_printf("hello %-10c 123\n", 'D');
		ft_printf("hello %*c 123\n", 16, 'D');
		ft_printf("hello %-*c 123\n", 10, 'D');
		ft_printf("hello %*c 123\n", -10, 'D');
		printf("hello %c 123\n", 'D');
		printf("hello %19c 123\n", 'D');
		printf("hello %-10c 123\n", 'D');
		printf("hello %*c 123\n", 16, 'D');
		printf("hello %-*c 123\n", 10, 'D');
		printf("hello %*c 123\n", -10, 'D');



		printf("\n-----------------------------\n");

		
		ft_printf("0%s0\n", "12345");
		printf("0%s0\n", "12345");

		ft_printf("0%10s0\n", "12345");
		printf("0%10s0\n", "12345");

		ft_printf("0%-10.2s0\n", "12345");
		printf("0%-10.2s0\n", "12345");
	
		ft_printf("0%10.s0\n", "12345");
		printf("0%10.s0\n", "12345");


		ft_printf("0%10.1s0\n", "12345");
		printf("0%10.1s0\n", "12345");


		ft_printf("0%10.0s0\n", "12345");
		printf("0%10.0s0\n", "12345");
		//printf("0%10.-3s0\n", "12345");


		ft_printf("0%10.*s0\n", -2, "12345");
		printf("0%10.*s0\n", -2, "12345");
	
		ft_printf("0%10.*s0\n", 2, "1");
		printf("0%10.*s0\n", 2, "1");
	
		printf("\n---------------------------\n");


		printf("1_%d_\n", 12345);	
		ft_printf("1_%d_\n", 12345);	

		printf("2_%06d_\n", 12345);	
		ft_printf("2_%06d_\n", 12345);	

		printf("3_%-8d_\n", 12345);	
		ft_printf("3_%-8d_\n", 12345);	

		printf("4_%8d_\n", 12345);	
		ft_printf("4_%8d_\n", 12345);	

		printf("5_%0*d_\n", 10, 12345);	
		ft_printf("5_%0*d_\n", 10, 12345);	

		printf("6_%0*d_\n", -10, -12345);	
		ft_printf("6_%0*d_\n", -10, -12345);	

		printf("7_%.d_\n", 12345);	
		ft_printf("7_%.d_\n", 12345);	

		printf("8_%010.6d_\n", 12345);	
		ft_printf("8_%010.6d_\n", 12345);	
		
		printf("81_%-10.6d_\n", 12345);	
		ft_printf("81_%-10.6d_\n", 12345);	
		
		printf("9_%1.10d_\n", 12345);	
		ft_printf("9_%1.10d_\n", 12345);	

		printf("10_%d_\n", 0);	
		ft_printf("10_%d_\n", 0);	

		printf("11_%.d_\n", 0);	
		ft_printf("11_%.d_\n", 0);	
		
		printf("12_%4.d_\n", 0);	
		ft_printf("12_%4.d_\n", 0);	
		
		printf("13_%03.d_\n", 0);	
		ft_printf("13_%03.d_\n", 0);	

		printf("\n---------------------------\n");


		printf("1_%u_\n", 12345);	
		ft_printf("1_%u_\n", 12345);	

		printf("2_%06u_\n", 12345);	
		ft_printf("2_%06u_\n", 12345);	

		printf("3_%-8u_\n", 12345);	
		ft_printf("3_%-8u_\n", 12345);	

		printf("4_%8u_\n", 12345);	
		ft_printf("4_%8u_\n", 12345);	

		printf("5_%0*u_\n", 10, 12345);	
		ft_printf("5_%0*u_\n", 10, 12345);	

		printf("6_%0*u_\n", -10, -12345);	
		ft_printf("6_%0*u_\n", -10, -12345);	

		printf("7_%.u_\n", 12345);	
		ft_printf("7_%.u_\n", 12345);	

		printf("8_%010.6u_\n", 12345);	
		ft_printf("8_%010.6u_\n", 12345);	
		
		printf("81_%-10.6u_\n", 12345);	
		ft_printf("81_%-10.6u_\n", 12345);	
		
		printf("9_%1.10u_\n", 12345);	
		ft_printf("9_%1.10u_\n", 12345);	

		printf("10_%u_\n", 0);	
		ft_printf("10_%u_\n", 0);	

		printf("11_%.u_\n", 0);	
		ft_printf("11_%.u_\n", 0);	
		
		printf("12_%4.u_\n", 0);	
		ft_printf("12_%4.u_\n", 0);	
		
		printf("13_%03.u_\n", 0);	
		ft_printf("13_%03.u_\n", 0);	
	
		printf("\n---------------------------\n");


		printf("1_%x_\n", 12345);	
		ft_printf("1_%x_\n", 12345);	

		printf("2_%06x_\n", 12345);	
		ft_printf("2_%06x_\n", 12345);	

		printf("3_%-8x_\n", 12345);	
		ft_printf("3_%-8x_\n", 12345);	

		printf("4_%8x_\n", 12345);	
		ft_printf("4_%8x_\n", 12345);	

		printf("5_%0*x_\n", 10, 12345);	
		ft_printf("5_%0*x_\n", 10, 12345);	

		printf("6_%0*x_\n", -10, -12345);	
		ft_printf("6_%0*x_\n", -10, -12345);	

		printf("7_%.x_\n", 12345);	
		ft_printf("7_%.x_\n", 12345);	

		printf("8_%010.6x_\n", 12345);	
		ft_printf("8_%010.6x_\n", 12345);	
		
		printf("81_%-10.6x_\n", 12345);	
		ft_printf("81_%-10.6x_\n", 12345);	
		
		printf("9_%1.10x_\n", 12345);	
		ft_printf("9_%1.10x_\n", 12345);	

		printf("10_%x_\n", 0);	
		ft_printf("10_%x_\n", 0);	

		printf("11_%.x_\n", 0);	
		ft_printf("11_%.x_\n", 0);	
		
		printf("12_%4.x_\n", 0);	
		ft_printf("12_%4.x_\n", 0);	
		
		printf("13_%03.x_\n", 0);	
		ft_printf("13_%03.x_\n", 0);	
	
		printf("\n---------------------------\n");


		printf("1_%X_\n", 12345);	
		ft_printf("1_%X_\n", 12345);	

		printf("2_%06X_\n", 12345);	
		ft_printf("2_%06X_\n", 12345);	

		printf("3_%-8X_\n", 12345);	
		ft_printf("3_%-8X_\n", 12345);	

		printf("4_%8X_\n", 12345);	
		ft_printf("4_%8X_\n", 12345);	

		printf("5_%0*X_\n", 10, 12345);	
		ft_printf("5_%0*X_\n", 10, 12345);	

		printf("6_%0*X_\n", -10, -12345);	
		ft_printf("6_%0*X_\n", -10, -12345);	

		printf("7_%.X_\n", 12345);	
		ft_printf("7_%.X_\n", 12345);	

		printf("8_%010.6X_\n", 12345);	
		ft_printf("8_%010.6X_\n", 12345);	
		
		printf("81_%-10.6X_\n", 12345);	
		ft_printf("81_%-10.6X_\n", 12345);	
		
		printf("9_%1.10X_\n", 12345);	
		ft_printf("9_%1.10X_\n", 12345);	

		printf("10_%X_\n", 0);	
		ft_printf("10_%X_\n", 0);	

		printf("11_%.X_\n", 0);	
		ft_printf("11_%.X_\n", 0);	
		
		printf("12_%4.X_\n", 0);	
		ft_printf("12_%4.X_\n", 0);	
		
		printf("13_%03.X_\n", 0);	
		ft_printf("13_%03.X_\n", 0);	

		
		printf("\n---------------------------\n");


		printf("1_%X_\n", 12345);	
		ft_printf("1_%X_\n", 12345);	

		printf("2_%06X_\n", 12345);	
		ft_printf("2_%06X_\n", 12345);	

		printf("3_%-8X_\n", 12345);	
		ft_printf("3_%-8X_\n", 12345);	

		printf("4_%8X_\n", 12345);	
		ft_printf("4_%8X_\n", 12345);	

		printf("5_%0*X_\n", 10, 12345);	
		ft_printf("5_%0*X_\n", 10, 12345);	

		printf("6_%0*X_\n", -10, -12345);	
		ft_printf("6_%0*X_\n", -10, -12345);	

		printf("7_%.X_\n", 12345);	
		ft_printf("7_%.X_\n", 12345);	

		printf("8_%010.6X_\n", 12345);	
		ft_printf("8_%010.6X_\n", 12345);	
		
		printf("81_%-10.6X_\n", 12345);	
		ft_printf("81_%-10.6X_\n", 12345);	
		
		printf("9_%1.10X_\n", 12345);	
		ft_printf("9_%1.10X_\n", 12345);	

		printf("10_%X_\n", 0);	
		ft_printf("10_%X_\n", 0);	

		printf("11_%.X_\n", 0);	
		ft_printf("11_%.X_\n", 0);	
		
		printf("12_%4.X_\n", 0);	
		ft_printf("12_%4.X_\n", 0);	
		
		printf("13_%03.X_\n", 0);	
		ft_printf("13_%03.X_\n", 0);	

	printf("\n---------------------------\n");


		ft_printf("0%10.*d0\n", -2, 12345);
		printf("0%10.*d0\n", -2, 12345);
	
		ft_printf("0%10.*d0\n", 2, 12345);
		printf("0%10.*d0\n", 2, 12345);
	
		ft_printf("[%.d]\n", 12345);
		printf("[%.d]\n", 12345);
	
		ft_printf("[%-6.011d]\n", 12345);
		printf("[%-6.011d]\n", 12345);
		
		ft_printf("[%.*d]\n", -1, 12345);
		printf("[%.*d]\n", -1, 12345);
       
	   	ft_printf("hello %s 123\n", "BOB");
		printf("hello %s 123\n", "BOB");

        ft_printf("hello %c 1 %s 2 %d 3 %i 4\n", 'D', "BOB", 192, -1212);
		printf("hello %c 1 %s 2 %d 3 %i 4\n", 'D', "BOB", 192, -1212);

        ft_printf("hell %u gg\n", 221232323);
		printf("hell %u gg\n", 221232323);

        ft_printf("hel %x ooo %X ooo\n", 4877, 3478347);
        printf("hel %x ooo %X ooo\n", 4877, 3478347);
       // printf("%lu\n", sizeof(void *));
	
	printf("\n---------------------------\n");

        char *s;
        s = malloc(1);
        
		ft_printf("%p\n", s);
        printf("%p\n", s);
		
		ft_printf("%30p\n", s);
        printf("%30p\n", s);
		
		ft_printf("%-20p\n", s);
        printf("%-20p\n", s);
		
		ft_printf("%30p\n", NULL);
        printf("%30p\n", NULL);
		
		//ft_printf("%.p\n", s);
        //printf("%.p\n", s);
		
		//ft_printf("%.40p\n", s);
        //printf("%.40p\n", s);

        free (s);
    }
    else
        ft_printf(NULL);
    //printf("\n");
    return (0);
}
