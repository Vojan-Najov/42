#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct	s_init
{
	int				id;
	int				philos_num;
	useconds_t		dtime;
	useconds_t		etime;
	useconds_t		stime;
	int				ecount;
	pthread_mutex_t	*data_mutex;
}				t_init;

int	ft_atoi(const char *str);

int	ft_isdigit(int c);

int	check_args(int argc, char **argv, t_init *info);

void	*philo_thread(void *v_data);

#endif

typedef struct	s_ph
{
	int		id;
	t_param	*param;
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;
}				t_ph;

typedef struct	s_args
{
	int				philos_num;
	useconds_t		dtime;
	useconds_t		etime;
	useconds_t		stime;
	int				ecount;
	t_ph			*phs;
	pthread_mutex_t	**forks;
}				t_args
