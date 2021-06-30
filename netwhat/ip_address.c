#include <stdio.h>
#include <stdlib.h>

int main()
{
	while (1)
	{
		int				b1, b2, b3, b4;
		int				mask;
		int 			ret;
		char			*bb;;
		int				size;
		int				i;
		unsigned int			hosts;

		ret = scanf("%d.%d.%d.%d/%d", &b1, &b2, &b3, &b4, &mask);
		if (ret <= 0)
			break ;
		
		i = mask;
		size = 32 - 1;
		printf("\n\nmask:\n");
		while (--i >= 0)
		{
			printf("1");
			if (size && (size % 8 == 0))
				printf(".");
			--size;
		}
		while (size >= 0)
		{
			printf("0");
			if (size && (size % 8 == 0))
				printf(".");
			--size;
		}



		size = 32;
		bb = malloc(size + 1);
		bb[size] = '\0';
		while (size >= 24)
		{
			bb[size--] = (b4 & 0x1) + '0';
			b4 >>= 1;
		}
		while (size >= 16)
		{
			bb[size--] = (b3 & 0x1) + '0';
			b3 >>= 1;
		}
		while (size >= 8)
		{
			bb[size--] = (b2 & 0x1) + '0';
			b2 >>= 1;
		}
		while (size >= 0)
		{
			bb[size--] = (b1 & 0x1) + '0';
			b1 >>= 1;
		}
	
		
		printf("\n\nip address:\n");
		
		for(i = 0; i < 8; ++i)
			printf("%c", bb[i]);
		printf(".");	
		for(i = 8; i < 16; ++i)
			printf("%c", bb[i]);
		printf(".");	
		for(i = 16; i < 24; ++i)
			printf("%c", bb[i]);
		printf(".");	
		for(i = 24; i < 32; ++i)
			printf("%c", bb[i]);
		printf("\n");
		

		printf("\nhosts count:  ");
		size = 32;
		hosts = 1;
		printf("i = %d\n", i);
		while (i > 0)
		{
			hosts *= 2;
			--i;
		}
		printf("%u  - 2\n", hosts);

		
		
		free(bb);
	}

	return (0);
}
