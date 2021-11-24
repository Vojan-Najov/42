#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

# define MALLOC_ERROR 1
# define ARGS_ERROR 2

typedef struct	s_args
{
	int				phs_num;
	useconds_t		dtime;
	useconds_t		etime;
	useconds_t		stime;
	int				ecount;
}				t_args;

typedef struct	s_ph
{
	int		id;
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;
	struct timeval	*death_time;
	t_args	*args;
}				t_ph;

int	ft_atoi(const char *str);

int	ft_isdigit(int c);

int	check_args(t_args *args, int argc, char **argv);

void	*philo_thread(void *v_data);

#endif
