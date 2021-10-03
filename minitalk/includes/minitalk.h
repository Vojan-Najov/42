/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:35:38 by ccartman          #+#    #+#             */
/*   Updated: 2021/09/23 17:03:23 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

# define BUFSIZE 256

int		print_args_error(void);

int		print_pid_error(void);

void	print_signal_error(void);

void	print_sigact_error(void);

void	print_write_error(void);

#endif
