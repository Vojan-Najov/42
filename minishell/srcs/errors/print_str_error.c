/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:01:19 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/17 15:33:00 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_errors.h"
#include "libft.h"

void	print_str_error(const char *str)
{
	char	*err;

	err = strerror(errno);
	write(STDERR_FILENO, g_shell_name, sizeof(g_shell_name) - 1);
	write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, err, ft_strlen(err));
	write(STDERR_FILENO, "\n", 1);
}

int	print_str_error_with_return(const char *str)
{
	print_str_error(str);
	return (1);
}

void	print_cmd_error(const char *name)
{
	write(STDERR_FILENO, g_shell_name, sizeof(g_shell_name) - 1);
	write(STDERR_FILENO, name, ft_strlen(name));
	write(STDERR_FILENO, g_cmd_error, sizeof(g_cmd_error) - 1);
}

void	print_dir_error(const char *name)
{
	write(STDERR_FILENO, g_shell_name, sizeof(g_shell_name) - 1);
	write(STDERR_FILENO, name, ft_strlen(name));
	write(STDERR_FILENO, g_dir_error, sizeof(g_dir_error) - 1);
}
