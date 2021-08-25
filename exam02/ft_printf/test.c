#include <stdio.h>
#include <stdlib.h>

int	ft_printf(const char *fmt, ...);

int	main(int argc, char **argv)
{
	int	a;
	int	b;

	if (argc == 3 || argc == 4)
	{
		if (argv[1][0] == 's')
		{
			a = printf(argv[2], argv[3]);
			printf("\n");
			b = ft_printf(argv[2], argv[3]);
			printf("\n");
			printf("p = %d   f = %d\n", a, b);
		}
		else if (argv[1][0] == 'd')
		{
			int n = atoi(argv[3]);
			a = printf(argv[2], n);
			printf("\n");
			b = ft_printf(argv[2], n);
			printf("\n");
			printf("p = %d   f = %d\n", a, b);
		}
		else if (argv[1][0] == 'x')
		{
			unsigned int n = atoi(argv[3]);
			a = printf(argv[2], n);
			printf("\n");
			b = ft_printf(argv[2], n);
			printf("\n");
			printf("p = %d   f = %d\n", a, b);
		}
	}
	return (0);
}
