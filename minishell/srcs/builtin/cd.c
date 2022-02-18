/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:19:00 by jjoan             #+#    #+#             */
/*   Updated: 2022/02/17 20:23:20 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "minishell_envp.h"
#include "minishell_errors.h"

static void	change_oldpwd(char *old)
{
	char	*set;

	set = ft_strjoin("OLDPWD=", old);
	if (!set)
	{
		print_str_error("malloc");
		free(old);
		return ;
	}
	ft_setenv(set);
	free(set);
	free(old);
}

static void	change_pwd(void)
{
	char	*set;
	char	*pwd;

	pwd = getcwd(0, 0);
	if (!pwd)
	{
		print_str_error("malloc");
		return ;
	}
	set = ft_strjoin("PWD=", pwd);
	if (!set)
	{
		free(pwd);
		print_str_error("malloc");
		return ;
	}
	free(pwd);
	ft_setenv(set);
	free(set);
}

static int	cd_home(void)
{
	int	ret;

	ret = 0;
	if (ft_getenv_with_name("HOME"))
	{
		if (!ft_getenv("HOME")[0])
			return (0);
		ret = chdir(ft_getenv("HOME"));
		if (ret)
			print_err("cd", ft_getenv("HOME"), FILE_OR_DIR_ERR);
		return (-ret);
	}
	else
		print_err("cd", NULL, HOME_NOT_SET);
	return (1);
}

int	ft_cd(char **s)
{
	int		ret;
	char	*old;

	old = getcwd(0, 0);
	if (!old)
		return (print_str_error_with_return("malloc"));
	if (!*s)
		ret = cd_home();
	else
	{
		ret = chdir(*s);
		if (ret)
		{
			print_err("cd", *s, FILE_OR_DIR_ERR);
			free(old);
			return (-ret);
		}
	}
	if (ft_getenv_with_name("OLDPWD") && !ret)
		change_oldpwd(old);
	if (ft_getenv_with_name("PWD") && !ret)
		change_pwd();
	return (ret);
}
