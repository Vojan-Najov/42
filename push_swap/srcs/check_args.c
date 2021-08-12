#include "push_swap.h"

static int	check_duplicates(char **args);

static int	check_limits(char **args);

int	check_args(char **args)
{
	int	i;
	int	j;

	i = -1;
	while (args[++i])
	{
		if (args[i][0] == '-')
			j = 0;
		else
			j = -1;
		while (args[i][++j])
			if (!ft_isdigit(args[i][j]))
				return (0);
	}
	if (!check_limits(args))
		return (0);
	if (!check_duplicates(args))
		return (0);
	return (1);
}

static int	check_limits(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
	{
		if (args[i][0] != '-')
		{
			if (ft_strlen(args[i]) > MAX_INT_STRLEN)
				return (0);
			else if (ft_strlen(args[i]) == MAX_INT_STRLEN \
				&& ft_strcmp(args[i], MAX_INT_STR) > 0)
				return (0);
		}
		else if (args[i][0] == '-')
		{
			if (ft_strlen(args[i]) > MIN_INT_STRLEN)
				return (0);
			else if (ft_strlen(args[i]) == MIN_INT_STRLEN && \
				ft_strcmp(args[i], MIN_INT_STR) > 0)
				return (0);
		}
	}
	return (1);
}

static int	check_duplicates(char **args)
{
	int	i;
	int	j;

	i = -1;
	while (args[++i])
	{
		j = i;
		while (args[++j])
		{
			if (ft_strcmp(args[i], args[j]) == 0)
				return (0);
		}
	}
	return (1);
}
