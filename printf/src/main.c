#include "printf.h"
#include <stdio.h>
#include <wchar.h>

int	main(void)
{
	
	//printf("\\!/%2lc\\!/", (char)207);

	//ft_printf("\\!/%2lc\\!/\n", (char)207);
//	ft_printf("%19lc\n", '1');
//	printf("\\!/%2lc\\!/\n", (char)207);
//	printf("%19lc\n", '1');
/*
	printf("_ %.s %.s_", "123", "4567");

	printf("\n----\n");

	ft_printf("_ %0.s %0.s_", "123", "4567");

	ft_printf("djajja%s\n", "1234422923923");

	printf("\n\n-------------------------\n\n");

	printf("%012.10x\n", 3);
	ft_printf("%012.10x\n", 3);

	printf("_%#10.x_\n", 0);
	
	printf("\n\n-------------------------\n\n");

	printf("_%012.10d_\n", 3);
	ft_printf("_%012.10d_\n", 3);
	printf("_%+1.10d_\n", 3);
	ft_printf("_%+1.10d_\n", 3);
	printf("_% 12.10d_\n", -12123);
	ft_printf("_% 12.10d_\n", -12123);
	printf("_%04d_\n", -1234);
	ft_printf("_%04d_\n", -1234);
	printf("_%.0d_\n", 0);
	ft_printf("_%.0d_\n", 0);

	printf("_%+4.d_\n", 0);
	ft_printf("_%+4.d_\n", 0);

	printf("_%+3.d_\n", 0);
	ft_printf("_%+3.d_\n", 0);

	printf("_%-5.0d_\n", 0);
	ft_printf("_%-5.0d_\n", 0);

	printf("%#o\n", 8);

	printf("\n\n-------------------------\n\n");

	printf("_%#03x_\n", 0);
	ft_printf("_%#-03x_\n", 0);

	printf("%lu\n%lu\n", sizeof(wint_t), sizeof(wchar_t));

	printf("%s%s\n", NULL, NULL);
	ft_printf("%s%s\n", NULL, NULL);

	wint_t lc = 903030;
	printf("%-4lc\n", lc);

	printf("\n\n-------------------------\n\n");


	for (wint_t i = 0; i <= 255; ++i)
	{
		int n = printf("%lc\n", i);
		printf("%d\n", n);
		//ft_printf("o%do\n", (int) i);
	}
*/
	int n = printf("_\n\n_");
	int k = ft_printf("0\n\n0");
	printf("%d_%d\n", n, k);

	printf("%lc\n", 100);
	ft_printf("%lc\n", 100);
	//sleep(1000);
	return (0);
}