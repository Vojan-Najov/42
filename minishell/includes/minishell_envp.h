/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_envp.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:10:24 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/17 11:40:02 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_ENVP_H
# define MINISHELL_ENVP_H

# include <stddef.h>

int		*get_exit_status_int_address(void);

char	**get_exit_status_str_address(void);

int		get_exit_status_int(void);

char	*get_exit_status_str(void);

void	set_exit_status(int status);

void	free_exit_status_str(void);

char	**get_envp(void);

char	***get_envp_adress(void);

char	**get_envp_copy(void);

int		init_envp(char **ev);

int		change_envp(int shift, char *ignore);

char	*ft_getenv_with_name(const char *s);

char	*ft_getenv(const char *s);

char	*get_name(const char *s);

int		ft_setenv(const char *arg);

int		check_env_to_set(const char *arg);

#endif
