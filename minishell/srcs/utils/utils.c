/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:49:51 by jjoan             #+#    #+#             */
/*   Updated: 2022/02/17 18:54:00 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>

void	free_str_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

size_t	mas_size(char **s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

void	std_signals(void)
{
	extern int	rl_catch_signals;

	rl_catch_signals = 1;
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
}

void	handler(int signal)
{
	if (signal == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	prepare_signals(void)
{
	extern int	rl_catch_signals;

	rl_catch_signals = 0;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handler);
}
