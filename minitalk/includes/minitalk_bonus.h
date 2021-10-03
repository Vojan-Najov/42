/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:36:16 by ccartman          #+#    #+#             */
/*   Updated: 2021/09/23 16:55:07 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

# define BUFSIZE 256

int		print_args_error(void);

int		print_pid_error(void);

void	print_signal_error(void);

void	print_sigact_error(void);

void	print_write_error(void);

pid_t	client_pid(pid_t pid);

void	print_pid(void);

int		ft_getpid(char *str);

#endif
