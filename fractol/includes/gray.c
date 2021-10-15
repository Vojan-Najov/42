/*
static const gray[] = {0xffffff,
						0xfcfcfc,
						0xfafafa,
						0xf7f7f7,
						0xf5f5f5

0	0x0
1	0x030303
2	0x050505
*/

#include <stdio.h>

int main()
{
	int	count;
	count = 0;
	int	c;
	
	c = 0x0;
	printf("%d      %X\n", count, c);
	while (count < 100)
	{
		if (count % 2 == 0)
			c += 0x030303;
		else
			c += 0x020202;

		++count;
		printf("%d      %X\n", count, c);
	}
}
