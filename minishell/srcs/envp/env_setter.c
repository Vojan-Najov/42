/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_setter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:30:52 by jjoan             #+#    #+#             */
/*   Updated: 2022/02/17 11:53:51 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "minishell_envp.h"
#include "minishell_errors.h"

static int	set_new_var(const char *s)
{
	char	**env;
	size_t	i;

	if (change_envp(1, NULL))
		return (1);
	env = get_envp();
	i = mas_size(env);
	env[i] = ft_strdup(s);
	if (!env[i])
	{
		change_envp(-1, NULL);
		print_str_error("malloc");
		return (1);
	}
	return (0);
}

static int	set_old_var(const char *s)
{
	char	*tmp;
	char	*name;
	char	**env;
	size_t	i;

	i = 0;
	env = get_envp();
	name = get_name(s);
	if (!name)
		return (print_str_error_with_return("malloc"));
	tmp = ft_getenv_with_name(name);
	free(name);
	while (env[i] != tmp)
		i++;
	env[i] = ft_strdup(s);
	if (!env[i])
	{
		env[i] = tmp;
		print_str_error("malloc");
		return (1);
	}
	free(tmp);
	return (0);
}

int	check_env_to_set(const char *arg)
{
	char	*name;
	size_t	i;
	int		ret;

	name = get_name(arg);
	if (!name)
		return (2);
	i = 0;
	if (name[i] != '_' && !ft_isalpha(name[i]))
	{
		free(name);
		return (1);
	}
	while (ft_isalnum(name[i]) || name[i] == '_')
		i++;
	if (i == ft_strlen(name))
		ret = 0;
	else
		ret = 1;
	free(name);
	return (ret);
}

int	ft_setenv(const char *arg)
{
	int		ret;
	char	*name;

	name = get_name(arg);
	if (!name)
		return (1);
	if (!ft_getenv_with_name(name))
		ret = set_new_var(arg);
	else
		ret = set_old_var(arg);
	free(name);
	return (ret);
}
