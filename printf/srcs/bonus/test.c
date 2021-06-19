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

	/*
	bigintinit();

	if (exp > 0)
	{
		bigint[0] = 1;	
		mask = 0x00FFFFFFFFFFF;
		raz = 52;
		while (exp > 0)
		{
			if (exp > 8)
				k = 8;
			else
				k = exp;
			
			n = mant >> (raz - k);
			mant &= mask;
			raz -= k;
			exp -= k;
		}			
	}
*/

	return (0);
}

/*

void bigintinit()
{
	for (int i = 0; i < SIZE; i++)
		digits[i] = 0;
}

    
    bigint() {                                  //стандартный конструктор
        for (int i = 0; i < SIZE; i++) {
            digits[i] = 0;
        }
    }

    bigint(long long x) {                       //конструктор для преобразования обычного числа в длинное
        for (int i = 0; i < SIZE; i++) {
            digits[i] = 0;
        }

        int next = 0;
        while (x) {
            digits[next++] = x % BASE;
            x /= BASE;
        }
    }

    bigint(const bigint& other) {           //конструктор копирования
        for (int i = 0; i < SIZE; i++) {
            digits[i] = other.digits[i];
        }
    }

    bigint& operator=(const bigint& other) {    //оператор присваивания
        for (int i = 0; i < SIZE; i++) {
            digits[i] = other.digits[i];
        }

        return *this;
    }

*/




























/*

	int	n;
	int m0, m1;
	int n0, n1;

	m0 = 0x100000 | f.m0;

		

	printf("HEX: %X  %x\n", f.m0, f.m1);
	n = 0;

	m1 = f.m1;

	if (exp <= 20)
		n = m0  >> (20 - exp);
	else
	{
		n0 = m0;
		n1 = m1 >> (32 + 20 - exp);
		//n <<= (exp - 20);
		//n += m1 >> (32 - exp);;

		printf("%d%d", n0, n1);
	}
	
	printf("\n%f\n", f.d);
	//printf("%lu\n", sizeof(f));	
	


	static const long long BASE = 1e9;     //размер разряда
    static const long long SIZE = 10;      //количество вмещаемых разрядов

    long long digits[SIZE];
	unsigned long long m;


	m = f.m0 << 32 | f.m1;
	
    for (int i = 0; i < SIZE; i++)
	{
		digits[i] = 0;
	}

	digits[0] = 1;

	long int	mask = 0x00FFFFFFFFFFF;
	while (exp > 0)
	{
		int t;
		if (exp > 8)
			 t = 8;
		else
			t = exp;
		int z = m >> (52 - t);
		
		m &= mask;
		mask >>= t;
		exp -= t;
	}

	int k = exp / 20;
	int i = 1;
	mask = 
	while (k)
	{
		long long l = m >> (52 - i * 20);
		m <<= 20;
		m &= mask;
	while (exp > 0)
	{
		int k = exp % 20;
		exp /= 20;
		long long l = m >> (52 - k);
		*digits += m >> (52 - i);
	return (0);
}
*/


/* длинная арифметика 3^100
   равно 515377520732011331036461129765621272702107522001 */


