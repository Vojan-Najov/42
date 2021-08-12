#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
# define TRUE 1 

int main(int argc, char **argv)
{
	int n;
	int k;
	
	if (argc != 2)
		return (1);
	k = atoi(argv[1]);
	srand(time(NULL));
	while (k--)
	{
		n = rand();
		printf("%d ", n);
		//sleep(1);
	}

	return (0);
}
