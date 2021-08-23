#include <unistd.h>
#define NL "\n"

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 3)
	{
		while (argv[1][i])
		{
			j = 0;
			while (argv[1][i] != argv[1][j])
				++j;
			if (i == j)
			{
				j = 0;
				while (argv[2][j])
				{
					if (argv[1][i] == argv[2][j])
					{
						write(1, &argv[1][i], 1);
						break ;
					}
					++j;
				}
			}
			++i;
		}
	}
	write(1, NL, 1);
	return (0);
}
