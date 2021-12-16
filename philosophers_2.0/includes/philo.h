#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

# define ARGS_ERROR 1
# define MALLOC_ERROR 2
# define MUTEX_ERROR 3
# define THREAD_ERROR 4
# define JOIN_ERROR 5

static const char	g_arg_err_mes[] = "Incorect arguments\n";
static const char	g_help_mes[] = "Usage:...\n";
static const char	g_mal_err_mes[] = "Memory allocation error \n";
static const char	g_mut_err_mes[] = "Mutex initialization error\n";
static const char	g_thr_err_mes[] = "Thread creation error\n";

typedef	struct s_ph	t_ph;

typedef struct	s_args
{
	int				phs_num;
	useconds_t		dtime;
	useconds_t		etime;
	useconds_t		stime;
	int				ecount;
	int				simulation;
	int				eaters;
	pthread_t		*ths;
	t_ph			*phs;
	int				*forks;
	pthread_mutex_t	*fork_mutexes;
	pthread_mutex_t date_mutex;
	pthread_mutex_t	simul;
}				t_args;

struct	s_ph
{
	int				id;
	int				eating;
	int				*first_fork;
	int				*second_fork;
	pthread_mutex_t	*first_fork_mutex;
	pthread_mutex_t	*second_fork_mutex;
	struct timeval	death_time;
	int				eat_count;
	int				ret;
	t_args			*args;
};

int		ft_atoi(const char *str);

int		ft_isdigit(int c);

int		check_args(t_args *args, int argc, char **argv);

int		init_args(t_args *args, int argc, char **argv);

void	completion(t_args *args, int forks_num, int date_mutex);

void	philo_think(t_ph *ph);

void	philo_eat(t_ph *ph);

void	philo_sleep(t_ph *ph);

void	*thread(void *v_data);

void	*watch(void *vph);

#endif
