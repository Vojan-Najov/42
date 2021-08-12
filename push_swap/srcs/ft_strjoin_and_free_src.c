#include "push_swap.h"

void	ft_strjoin_and_free_src(char **src, const char *part)
{
	char	*tmp;

	tmp = *src;
	*src = ft_strjoin(tmp, part);
	free(tmp);
}
