/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 14:54:14 by ccartman          #+#    #+#             */
/*   Updated: 2022/01/02 15:48:29 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <string.h>
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
static const char	g_mutd_err_mes[] = "Mutex destruction error\n";
static const char	g_thr_err_mes[] = "Thread creation error\n";
static const char	g_thrj_err_mes[] = "Thread joining error\n";

typedef struct s_ph	t_ph;

typedef struct s_args
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
	pthread_mutex_t	*forks;
	pthread_mutex_t	date_mutex;
	pthread_mutex_t	simul;
	struct timeval	start;
}	t_args;

struct	s_ph
{
	int				id;
	int				eating;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
	struct timeval	death_time;
	int				eat_count;
	int				ret;
	t_args			*args;
};

int				ft_atoi(const char *str);

int				ft_isdigit(int c);

unsigned long	gettimeofsimulation(t_args *args);

int				check_args(t_args *args, int argc, char **argv);

int				init_args(t_args *args, int argc, char **argv);

void			completion(t_args *args, int forks_num, int date_mutex, \
															int simul_mutex);

void			ft_usleep(long time, t_args *args);

void			philo_think(t_ph *ph);

void			philo_eat(t_ph *ph);

void			philo_sleep(t_ph *ph);

void			*thread(void *v_data);

void			*watch(void *vph);

#endif
