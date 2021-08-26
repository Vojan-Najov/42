#include "get_next_line.h"
#include <stdio.h>

int main()
{
	char	*line;
	int		ret;

	line = NULL;
	while ((ret = get_next_line(&line)))
	{
		if (ret == -1)
		{
			printf("READ ERROR\n");
			free(line);
			return (0);
		}
		printf("%s\n", line);
		free(line);
	}
	printf("ret = %d\nline =_%s_\n", ret, line);
	free(line);
	return (0);
}
