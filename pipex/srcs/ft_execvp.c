#include "pipex.h"

int	ft_exec(const char *path, char *const env[])
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (path[i])
	{
		if (path[i] == '/')
		{
			falg = 1;
			break ;
		}
		++i;
	}
	if (flag)
	{
//split
}
