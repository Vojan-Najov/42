#ifndef PHILO_H
# define PHILO_H

# include <fcntl.h>
# include <sys/stat.h> 
# include <semaphore.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <signal.h>

# define ARGS_ERROR 1
# define MALLOC_ERROR 2
# define SEMAPHORE_ERROR 3
# define THREAD_ERROR 4
# define JOIN_ERROR 5
# define FORK_ERROR 6
# define GETTIME_ERROR 7

static const char	g_arg_err_mes[] = "Incorect arguments\n";
static const char	g_help_mes[] = "Usage:...\n";
static const char	g_mal_err_mes[] = "Memory allocation error \n";
static const char	g_sem_unl_mes[] = "Semaphore unlinking error\n";
static const char	g_sem_open_mes[] = "Semaphore opening error\n";
static const char	g_sem_close_mes[] = "Semaphore closing error\n";
static const char	g_thr_err_mes[] = "Thread creation error\n";

typedef	struct s_ph	t_ph;

typedef struct	s_args
{
	int				phs_num;
	useconds_t		dtime;
	useconds_t		etime;
	useconds_t		stime;
	int				ecount;
	int				id;
	int				eat_count;
	sem_t			*date_sem;
	sem_t			*forks_sem;
	sem_t			*end_sem;
	pid_t			*pids;
	struct timeval	start;  //
	struct timeval	death_time;  //
}				t_args;

struct	s_ph
{
	int				id;
	int				eating;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
	struct timeval	death_time;
	int				eat_count;
	int				ret;
	t_args	*args;
};

int		ft_atoi(const char *str);

int		ft_isdigit(int c);

unsigned long	gettimeofsimulation(t_args *args);

int		check_args(t_args *args, int argc, char **argv);

int		init_args(t_args *args, int argc, char **argv);

void	completion(t_args *args, int forks_sem, int date_sem, int end_sem);

void	ft_usleep(long time, t_args *args);

void	philo_think(t_args *args);

void	philo_eat(t_args *args);

void	philo_sleep(t_args *args);

void	*thread(void *v_data);

void	*watch(void *vph);

#endif
