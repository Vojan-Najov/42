/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:58:06 by jjoan             #+#    #+#             */
/*   Updated: 2022/02/14 14:09:04 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

int	ft_echo(char **s);

int	ft_cd(char **s);

int	ft_pwd(char **str);

int	ft_export(char **s);

int	ft_unset(char **s);

int	ft_env(char **s);

int	ft_exit(char **s);

#endif
