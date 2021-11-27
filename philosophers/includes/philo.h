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

static const char	g_arg_err_mes[] = "Incorect arguments\n";
static const char	g_mut_err_mes[] = "Incorect arguments\n";

typedef	struct s_ph	t_ph;

typedef struct	s_args
{
	int				phs_num;
	useconds_t		dtime;
	useconds_t		etime;
	useconds_t		stime;
	int				ecount;
	t_ph			*phs;
	pthread_mutex_t	*forks;
	pthread_mutex_t write_mutex;
}				t_args;

struct	s_ph
{
	int		id;
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;
	struct timeval	*death_time;
	t_args	*args;
};

int		ft_atoi(const char *str);

int		ft_isdigit(int c);

int		check_args(t_args *args, int argc, char **argv);

int		init_args(t_args *args, int argc, char **argv);

void	completion(t_args *args);

void	*philo_thread(void *v_data);

#endif
