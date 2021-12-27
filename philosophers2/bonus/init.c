#include "philo_bonus.h"

int	init_args(t_args *args, int argc, char **argv)
{
	int	ret;

	memset(args, 0, sizeof(t_args));
	ret = check_args(args, argc, argv);
	if (ret)
	{
		write(STDERR_FILENO, g_arg_err_mes, sizeof(g_arg_err_mes));
		write(STDIN_FILENO, g_help_mes, sizeof(g_help_mes));
		return (ARGS_ERROR);
	}
	args->pids = (pid_t *) malloc(sizeof(pid_t) * args->phs_num);
	if (!args->pids)
		return (MALLOC_ERROR);
	//args->forks_sem = sem_open("forks", O_CREAT, S_IWUSR, args->phs_num);
	sem_unlink("forks");
	args->forks_sem = sem_open("forks", O_CREAT, S_IRWXU, args->phs_num);
	if (!args->forks_sem)
	{
		perror("sem error:");
		return (6); //SEMAPHORE_ERROR
	}
	sem_unlink("date");
	args->date_sem = sem_open("date", O_CREAT, S_IWUSR, 1);
	if (!args->date_sem)
		return (6); // SEMAPHORE_ERROR
	sem_unlink("death");
	args->death_sem = sem_open("death", O_CREAT, S_IWUSR, 0);
	if (!args->death_sem)
		return (6); // SEMAPHORE_ERROR
	return (0);
}
