#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

typedef struct	s_init
{
	int				philo_num;
	susseconds_t	dtime;
	susseconds_t	etime;
	susseconds_t	stime;
	int				ecount;
}				t_init;

int	ft_atoi(const char *str);

int	ft_isdigit(int c);

#endif
