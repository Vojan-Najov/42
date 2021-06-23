#include <stdio.h>
#include <stdlib.h>

typedef union	u_float
{
	double	d;
	struct
	{
		unsigned int		m1:32;
		unsigned int		m0:20;
		unsigned int		exp:11;
		unsigned int		sign:1;
	};
}				t_float;

//static const long long	BASE = 1e9;     
//static const long long	SIZE = 10;     
//static long long		digits[SIZE];

void bigintinit();

int	main(void)
{
	t_float		f;
	int			exp;
	int			sign;
	long int	mant;
	//int			k;
	//long long	n;
	//long long	mask;
	//int			raz;

	f.d = 1024. * 1024. * 1024. *1024. + 1.37378282;
	f.d = 0.1;	
	exp = f.exp - 1023;
	printf("%d\n", exp);

	sign = f.sign;
	printf("%d\n", f.sign);
	
	mant = 0x100000 | f.m0;
	mant <<= 32;
	mant |= f.m1;
	printf("HEX mant: %lX\n", mant);


	while (1)
	{
		long long int	*p;
		double d;
		int		e;
		int res = scanf("%lf", &d);
		if (res <= 0)
			break;
		
		p = (long long int *) &d;
		sign = (*p >> 63) & 1;
		e = (*p >> 52) & 0x7FF;
		exp = e - 1023;
		mant = *p & 0xFFFFFFFFFFFFFL;
		mant |=  0x10000000000000L;
		printf("exp = %d\n", exp);
		unsigned long long mask = 0x10000000000000;
		int i = 0;
		while (mask != 0)
		{ 
			++i;
			if ((mask & mant) != 0)
				printf("1");
			else
				printf("0");
			if (i == 1)
				printf(".");
			if (i == exp + 1)
				printf(",");
			mask >>= 1;
		}
		printf("---%d", i);
		printf("\n");



	/////////////////////////////////////////////////////
	
		if (52 <= exp && exp <= 64)
		{
			unsigned long long n = mant << (exp - 52);
			int t = 0;
			printf("\n\n%llu%c%d\n", n, '.', t);
			printf("%f\n", d);
		}
		else if (exp < 52)
		{
			unsigned long long n;
			int k;
			unsigned long long b;
			unsigned long long	*a;
			int i, j;
			int carry;
			int length;

			k = 52 - exp; 
			n = mant >> k;
			k = (11 + 1 + exp);
			mant <<= k;
			mant >>= k;
		

			k = 52 - exp;
			a = malloc(sizeof(long long) * k);
			while (--k >= 0)
			{
				b = mant & 0x1L;
				mant >>= 1;
				a[k] = b;
			}
			for (int v = 0; v < 52 - exp; ++v)
				printf("%llu", a[v]);
			printf("\n");
			
			length = 0;
			k = 52 - exp;
			while (--k >= 0)
			{
				if (a[k])
				{
					length = k;
					break ;
				}			
			}
			k = 52 - exp;
			i = 0;
			while (i < k)
			{
				j = i - 1;
				while (++j < k)
				a[j] *= 5;
				++i;
			}
			carry = 0;
		
			while (--k > 0)
			{
				carry = a[k] / 10;
				a[k] %= 10;
				a[k-1] += carry;
			}
			printf("%d___%llu\n", k, a[k]);
			//	a[k] %= 10;
	
			k = 52 - exp;
			i = 0;
		
			printf("\n\n%llu%c", n, '.');
			while (i < k)
			{
				printf("%llu", a[i]);
				++i;
			}
			printf("\n");

			printf("%.10f\n\n\n", d);
		}
	}

	return (0);
}
