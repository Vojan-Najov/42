/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_getter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:23:00 by jjoan             #+#    #+#             */
/*   Updated: 2022/02/17 11:53:05 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell_envp.h"

char	*ft_getenv_with_name(const char *s)
{
	size_t	i;
	size_t	len;
	char	**env;

	env = get_envp();
	i = 0;
	len = ft_strlen(s);
	while (env[i]
		&& !(!ft_strncmp(env[i], s, len)
			&& ((*(env[i] + len) == '=') || (*(env[i] + len) == 0))))
		i++;
	if (!env[i])
		return (NULL);
	return (env[i]);
}

char	*ft_getenv(const char *s)
{
	char	*ret;

	ret = ft_getenv_with_name(s);
	if (ret)
		return (ret + ft_strlen(s) + 1);
	return (NULL);
}

char	*get_name(const char *s)
{
	char	*name;
	size_t	i;

	if (!ft_strchr(s, '='))
		return (ft_strdup(s));
	i = (ft_strchr(s, '=') - s) + 1;
	name = malloc(sizeof(char) * (i));
	if (!name)
		return (NULL);
	if (ft_strlen(s) == ft_strlcpy(name, s, i))
		return (name);
	free(name);
	return (NULL);
}
