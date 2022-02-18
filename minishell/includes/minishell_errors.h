/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_errors.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:49:52 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/17 19:19:01 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_ERRORS_H
# define MINISHELL_ERRORS_H

# include <errno.h>
# include <string.h>
# include <unistd.h>

# define ARG_ERR "too many arguments\n"
# define NUM_ERR "numeric argument required\n"
# define FILE_OR_DIR_ERR "No such file or directory\n"
# define NOT_VALID_ERR "not a valid identifier\n"
# define HOME_NOT_SET "HOME not set\n"

static const char	g_cmd_error[] = ": command not found\n";

static const char	g_dir_error[] = ": is a directory\n";

void	print_str_error(const char *str);

void	print_cmd_error(const char *name);

void	print_dir_error(const char *name);

void	print_err(const char *name, const char *arg, const char *err);

int		print_str_error_with_return(const char *str);

int		error_free_table(size_t num, char **tmp);

void	error_copy_free_table(size_t num, char ***envp_copy);

#endif
