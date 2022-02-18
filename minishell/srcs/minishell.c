/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:38:45 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/18 13:21:01 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>
#include "minishell_envp.h"
#include <signal.h>

static void	redefine_signals(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

static void	completion(void)
{
	char	**envp;

	write(STDOUT_FILENO, "\033[1A$> exit\n", sizeof("\033[1A$> exit\n") - 1);
	free_exit_status_str();
	envp = get_envp();
	free_str_tab(envp);
	exit(EXIT_SUCCESS);
}

static void	minishell(void)
{
	char	*str;
	t_cmds	*cmds;

	while (1)
	{
		prepare_signals();
		str = readline(g_prompt);
		redefine_signals();
		if (!str)
			completion();
		if (!*str)
		{
			free(str);
			continue ;
		}
		add_history(str);
		cmds = parse(str);
		free(str);
		if (!cmds)
			continue ;
		execution(cmds);
	}
}

int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	prepare_env(envp);
	minishell();
}
