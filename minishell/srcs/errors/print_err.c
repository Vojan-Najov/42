/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:49:51 by jjoan             #+#    #+#             */
/*   Updated: 2022/02/17 11:10:37 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_envp.h"
#include "minishell_errors.h"
#include "libft.h"

void	print_err(const char *name, const char *arg, const char *err)
{
	write(STDERR_FILENO, g_shell_name, sizeof(g_shell_name) - 1);
	write(STDERR_FILENO, name, ft_strlen(name));
	write(STDERR_FILENO, ": ", 2);
	if (arg)
	{
		write(STDERR_FILENO, "'", 1);
		write(STDERR_FILENO, arg, ft_strlen(arg));
		write(STDERR_FILENO, "': ", 3);
	}
	write(STDERR_FILENO, err, ft_strlen(err));
}

int	error_free_table(size_t num, char **tmp)
{
	char	***envp;
	size_t	i;

	envp = get_envp_adress();
	i = -1;
	while (++i < num)
		free((*envp)[i]);
	free(*envp);
	*envp = tmp;
	print_str_error("malloc");
	return (1);
}

void	error_copy_free_table(size_t num, char ***envp_copy)
{
	char	**envp;
	size_t	i;

	i = -1;
	envp = *envp_copy;
	while (++i < num)
		free(envp[i]);
	free(envp);
}
