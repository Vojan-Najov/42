/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:29:21 by jjoan             #+#    #+#             */
/*   Updated: 2022/02/17 11:50:59 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "minishell_envp.h"
#include "minishell_errors.h"

static void	print_export(const char *s)
{
	write(STDOUT_FILENO, "declare -x ", 11);
	if (ft_strchr(s, '='))
	{
		write(STDOUT_FILENO, s, ft_strchr(s, '=') - s + 1);
		write(STDOUT_FILENO, "\"", 1);
		write(1, ft_strchr(s, '=') + 1, ft_strlen(ft_strchr(s, '=')) - 1);
		write(STDOUT_FILENO, "\"\n", 2);
	}
	else
	{
		write(STDOUT_FILENO, s, ft_strlen(s));
		write(STDOUT_FILENO, "\n", 1);
	}
}

static void	ft_sort_string_tab(char **strs)
{
	int		i;
	int		j;
	int		n;
	char	*key;

	n = (int) mas_size(strs);
	if (n < 2 || !strs)
		return ;
	i = 1;
	while (i < n)
	{
		key = strs[i];
		j = i - 1;
		while (j >= 0 && ft_strcmp(strs[j], key) > 0)
		{
			strs[j + 1] = strs[j];
			--j;
		}
		strs[j + 1] = key;
		++i;
	}
	i = 0;
	while (strs[i])
		print_export(strs[i++]);
}

int	print_sort_env(void)
{
	char	**env;

	env = get_envp_copy();
	if (!env)
	{
		print_str_error("malloc");
		return (1);
	}
	ft_sort_string_tab(env);
	free_str_tab(env);
	return (0);
}

int	ft_export(char **s)
{
	int	i;
	int	ret;

	i = -1;
	ret = 1;
	if (mas_size(s) == 0)
		ret = print_sort_env();
	else
	{
		while (s[++i])
		{
			if (ft_getenv_with_name(s[i]))
				continue ;
			if (!check_env_to_set(s[i]))
				ret = ft_setenv(s[i]);
			else
				print_err("export", s[i], NOT_VALID_ERR);
		}
	}
	return (ret);
}
