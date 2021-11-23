#include "philo.h"

static int	check_args(int argc, char **argv, t_init *info);

static int	check_arg(char *arg);

int	main(int argc, char **argv)
{
	t_init	info;

	check_args(argc, argv, &info);
	
}

static int	check_args(int argc, char **argv, t_init *info)
{
	if (argc != 5 || argc != 6)
		return (0);   //print info mess
	if (!check_arg(argv[1]))
		return (0);
	info->philos_num = ft_atoi(argv[1]);
	if (!check_arg(argv[2]))
		return (0);
	info->dtime = ft_atoi(argv[2]);
	if (!check_arg(argv[3]))
		return (0);
	info->etime = ft_atoi(argv[3]);
	if (!check_arg(argv[4]))
		return (0);
	info->stime = ft_atoi(argv[4]);
	if (argc == 6)
	{
		if (!check_arg(argv[1]))
			return (0);
		info->ecount = ft_atoi(argv[5]);
	}
	return (1);
}

static int	check_arg(char *arg)
{
	if (*arg == '+')
		++arg;
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (0);
		++arg;
	}
	return (1);
}
