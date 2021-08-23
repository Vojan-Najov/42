#include <stdio.h>
#include <stdlib.h>

int	ft_printf(const char *fmt, ...);

int	main(int argc, char **argv)
{
	if (argc == 3 || argc == 4)
	{
		if (argv[1][0] == 's')
		{
			printf(argv[2], argv[3]);
			printf("\n");
			ft_printf(argv[2], argv[3]);
			printf("\n");
		}
		else if (argv[1][0] == 'd')
		{
			int n = atoi(argv[3]);
			printf(argv[2], n);
			printf("\n");
			ft_printf(argv[2], n);
			printf("\n");
		}
		else if (argv[1][0] == 'x')
		{
			unsigned int n = atoi(argv[3]);
			printf(argv[2], n);
			printf("\n");
			ft_printf(argv[2], n);
			printf("\n");
		}
	}
	return (0);
}
