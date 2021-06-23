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


	int n = printf("_\n\n_");
	int k = ft_printf("0\n\n0");
	printf("%d_%d\n", n, k);

	printf("%lc\n", 100);
	ft_printf("%lc\n", 100);


	for (wint_t i = 0; i <= 0x10ffff; ++i)
	{
		int n = ft_printf("_%4lc_\n", i);
		ft_printf("%d\n", n);
		//ft_printf("o%do\n", (int) i);
	}

	int n, k;

	n = ft_printf("[%46c]", (char) -56);
	k = printf("[%46c]", (char) -56);
	printf("\nftp: %d   p: %d\n", n, k);

	n = ft_printf("[%46c]", (char) -100);
	k = printf("[%46c]", (char) -100);
	printf("\nftp: %d   p: %d\n", n, k);

	n = ft_printf("!%12c!", (char)-86);
	k = printf("!%12c!", (char)-86);
	printf("\nftp: %d   p: %d\n", n, k);

	n = ft_printf("123");
	k = printf("123");
	printf("\nftp: %d   p: %d\n", n, k);

	n = ft_printf("!%40lc!", (char)251);
	k = printf("!%40lc!", (char)251);
	printf("\nftp: %d   p: %d\n", n, k);

	n = ft_printf("%40lc", (char)16);
	k = printf("%40lc", (char)16);
	printf("\nftp: %d   p: %d\n", n, k);

	n = ft_printf("^.^/%40lc^.^/",(char)16);
	k = printf("^.^/%40lc^.^/", (char)16);
	printf("\nftp: %d   p: %d\n", n, k);
	
	n = ft_printf("123");
	k = printf("123");
	printf("\nftp: %d   p: %d\n", n, k);

	int n, k;

	n = ft_printf("%#05x\n", 43);
	k = printf("%#05x\n", 43);
	printf("\nftp: %d   p: %d\n", n, k);

	n = ft_printf("%#-5x\n", 43);
	k = printf("%#-5x\n", 43);
	printf("\nftp: %d   p: %d\n", n, k);

	n = ft_printf("%+ld\n", 22337203685477l);
	k = printf("%+ld\n", 22337203685477l);
	printf("\nftp: %d   p: %d\n", n, k);
	
	n = ft_printf("%+d\n", 2233720);
	k = printf("%+d\n", 2233720);
	printf("\nftp: %d   p: %d\n", n, k);

	n = ft_printf("%#037lX\n", 22337203685477ul);
	k = printf("%#037lX\n", 22337203685477ul);
	printf("\nftp: %d   p: %d\n", n, k);

	n = ft_printf(" %.s %.s ", "123", "4567");
	k = printf(" %.s %.s ", "123", "4567");
	printf("\nftp: %d   p: %d\n", n, k);
	
	n = ft_printf(" %lc \n", u'ƀ');
	k = printf(" %lc \n", u'ƀ');
	printf("\nftp: %d   p: %d\n", n, k);

	for (wint_t i = 0; i <= 0x10ffff; ++i)
	{
		int n = printf("_%4lc_\n", i);
		printf("\n");
		int	k = ft_printf("_%4lc_\n", i);
		ft_printf("p : %d   ftp : %d\n\n", n, k);
		//ft_printf("o%do\n", (int) i);
	}

	int n, k;
	wchar_t w1, w2, w3, w4, w5, w6;

	w1 = ' ';
	w2 = u'ƀ';
	w3 = u'ɏ';
   	w4 = u'ɐ';
	w5 = u'ʯ';
	w6 = 0;

	wchar_t	 s[] = {' ', u'ƀ', u'ɏ', u'ɐ', ' ', u'ʯ', ' ', \
	u'ʰ', u'˿', ' ', u'ୟ', ' ', u'௫', ' ', ' ', u'࿚', 0};
	//wchar_t	s[6] = {w1, w2, w3, w4, w5, w6};

	ft_printf("%s\n", "123");
	n = ft_printf("%ls\n", s);
	printf("%d\n", n);
	
	n = ft_printf("%ls\n", NULL);
	printf("%d\n", n);

	
	n = ft_printf("%#05x\n", 43);
	k = printf("%#05x\n", 43);
	printf("\nftp: %d   p: %d\n", n, k);


	n = ft_printf("%#05X\n", 43);
	k = printf("%#05X\n", 43);
	printf("\nftp: %d   p: %d\n", n, k);
	
	for (wint_t i = 0; i <= 0x10ffff; ++i)
	{
		//int n = printf("_%i-4lc_\n", i);
		//printf("\n");
		int	k = ft_printf("_%4lc_\n", i);
		ft_printf("p : %d\n\n", k);
		//ft_printf("o%do\n", (int) i);
	}


	int n, k;

	n = 0;
	printf("1234567890%n123\n", &n);
	printf("%d\n", n);

	n = 0;
	ft_printf("1234567890%n123\n", &n);
	ft_printf("%d\n", n);


	n = ft_printf("%-#5o\n", 43);
	k = printf("%-#5o\n", 43);
	printf("\nftp: %d   p: %d\n", n, k);

	printf("123%n\n", &n);

	wchar_t	 s[] = {' ', u'ƀ', u'ɏ', u'ɐ', ' ', u'ʯ', ' ', \
	u'ʰ', u'˿', ' ', u'ୟ', ' ', u'௫', ' ', ' ', u'࿚', 0};
	//wchar_t	s[6] = {w1, w2, w3, w4, w5, w6};

	ft_printf("%s\n", "123");
	n = ft_printf("%ls\n", s);
	printf("%d\n", n);
	
	n = ft_printf("%ls\n", NULL);
	printf("%d\n", n);
	
	n = ft_printf("%#05x\n", 43);
	k = printf("%#05x\n", 43);
	printf("\nftp: %d   p: %d\n", n, k);


	*/
	while (1)
	{
		double d;
		int ret;

		ret = scanf("%lf", &d);
		if (ret <= 0)
			break ;

		ft_printf("ftp: _%.f_\n", d);

		printf("p:   _%.f_\n", d);
	}
	ft_printf("%f\n", 4.5);
	//sleep(1000);
	//

	ft_printf("_%-7.f_%-8.1f_%-9.2f_\n", 0.0, -1.0, 0.0);
	printf("_%-7.f_%-8.1f_%-9.2f_\n", 0.0, -1.0, 0.0);

	ft_printf("_%-7.f_%-8.1f_%-9.2f_\n", 0.0, -1.0, 42.0);
	printf("_%-7.f_%-8.1f_%-9.2f_\n", 0.0, -1.0, 42.0);

	ft_printf("_%07.f_%08.1f_%09.2f_\n", 0.0, -1.0, 42.0);
	printf("_%07.f_%08.1f_%09.2f_\n", 0.0, -1.0, 42.0);

	ft_printf("_%.16f_%.16f_\n", 0.01234567890123456789012345678901, -0.01234567890123456789012345678901);
	printf("_%.16f_%.16f_\n", 0.01234567890123456789012345678901, -0.01234567890123456789012345678901);


	ft_printf("%.52f\n", 4.5);
	printf("%.520f\n", 4.5);

	ft_printf("%.0f\n", 2.51);
	printf("%.0f\n", 2.51);

	ft_printf("%.100f\n", 1.5);
	printf("%.100f\n", 1.5);

	return (0);
	
}
