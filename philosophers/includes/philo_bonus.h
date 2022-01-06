/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:54:10 by ccartman          #+#    #+#             */
/*   Updated: 2022/01/06 19:28:51 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <sys/stat.h> 
# include <semaphore.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>

# define ARGS_ERROR 1
# define MALLOC_ERROR 2
# define SEMAPHORE_ERROR 3
# define THREAD_ERROR 4
# define DETACH_ERROR 5
# define FORK_ERROR 6
# define GETTIME_ERROR 7
# define FORKS_SEM "/forks"
# define DATE_SEM "/date"
# define EATERS_SEM "/eaters"
# define END_SEM "/end"

static const char	g_arg_err_mes[] = "Incorect arguments\n";
static const char	g_help_mes[] = "Usage: "
	"./philo number_of_philosophers time_to_die "
	"time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n";
static const char	g_mal_err_mes[] = "Memory allocation error \n";
static const char	g_sem_unl_mes[] = "Semaphore unlinking error\n";
static const char	g_sem_open_mes[] = "Semaphore opening error\n";
static const char	g_sem_close_mes[] = "Semaphore closing error\n";
static const char	g_thr_err_mes[] = "Thread creation error\n";
static const char	g_dtch_err_mes[] = "Thread detaching error\n";
static const char	g_fork_err_mes[] = "Fork creation error\n";
static const char	g_gettime_err_mes[] = "Getting time of day error\n";

typedef struct s_ph	t_ph;

typedef struct s_args
{
	int				phs_num;
	useconds_t		dtime;
	useconds_t		etime;
	useconds_t		stime;
	int				ecount;
	int				id;
	int				end;
	sem_t			*date_sem;
	sem_t			*forks_sem;
	sem_t			*end_sem;
	sem_t			*eaters_sem;
	pid_t			*pids;
	struct timeval	start;
	struct timeval	death_time;
}				t_args;

int				ft_atoi(const char *str);

int				ft_isdigit(int c);

unsigned long	gettimeofsimulation(t_args *args);

int				check_args(t_args *args, int argc, char **argv);

int				init_args(t_args *args, int argc, char **argv);

void			completion(t_args *args);

void			ft_usleep(long time, t_args *args);

void			philo_think(t_args *args);

void			philo_eat(t_args *args);

void			philo_sleep(t_args *args);

int				philosopher(t_args *args);

#endif
