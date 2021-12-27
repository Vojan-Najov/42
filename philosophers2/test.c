#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{

	int	pid;
	int	*a;

	a = malloc(sizeof(int));
	*a = 0;
	pid = fork();
	if (pid == 0)
	{
		*a = 1;
		usleep(1000);
		printf("a = %d\n", *a);
	}
	else
	{
		usleep(100);
		printf("a = %d\n", *a);
		*a = 2;
	}
	return (0);
}
