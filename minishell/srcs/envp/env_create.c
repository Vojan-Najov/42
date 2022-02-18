/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:58:38 by jjoan             #+#    #+#             */
/*   Updated: 2022/02/17 21:02:28 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "minishell_envp.h"
#include "minishell_errors.h"

char	***get_envp_adress(void)
{
	static char	**envp;

	return (&envp);
}

char	**get_envp(void)
{
	char	***envp;

	envp = get_envp_adress();
	return (*envp);
}

char	**get_envp_copy(void)
{
	size_t	len;
	size_t	i;
	char	**envp;
	char	**envp_copy;

	envp = get_envp();
	len = mas_size(envp);
	envp_copy = malloc(sizeof(char *) * (len + 1));
	if (!envp_copy)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		envp_copy[i] = ft_strdup(envp[i]);
		if (!envp_copy[i])
		{
			error_copy_free_table(i, &envp_copy);
			return (NULL);
		}
	}
	envp_copy[i] = NULL;
	return (envp_copy);
}

int	init_envp(char **ev)
{
	size_t	i;
	char	***envp;

	envp = get_envp_adress();
	*envp = malloc(sizeof(char *) * (mas_size(ev) + 1));
	if (!(*envp))
		return (1);
	i = -1;
	while (++i < mas_size(ev))
	{
		(*envp)[i] = ft_strdup(ev[i]);
		if (!(*envp)[i])
			return (error_free_table(i, NULL));
	}
	(*envp)[i] = NULL;
	return (0);
}

int	change_envp(int shift, char *ignore)
{
	size_t	i;
	size_t	j;
	char	**tmp;
	char	***env;

	i = 0;
	j = 0;
	tmp = get_envp();
	env = get_envp_adress();
	*env = malloc(sizeof(char *) * (mas_size(tmp) + 1 + shift));
	if (!(*env))
		return (error_free_table(0, tmp));
	while (i <= mas_size(tmp) + shift)
	{
		if (tmp[j] != ignore && i < mas_size(tmp))
			(*env)[i++] = tmp[j++];
		else if (ignore && tmp[j] == ignore)
			free(tmp[j++]);
		else
			(*env)[i++] = NULL;
	}
	free(tmp);
	return (0);
}
