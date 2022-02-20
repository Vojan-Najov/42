/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:21:54 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/20 14:58:37 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>

static int	completion(char *str, int *cntrlc, int status, int fd);

static sig_atomic_t	*get_cntrlc(void)
{
	static sig_atomic_t	cntrlc;

	return (&cntrlc);
}

static void	heredoc_handler_sigint(int sig)
{
	sig_atomic_t	*cntrlc;

	if (sig != SIGINT)
		return ;
	cntrlc = get_cntrlc();
	*cntrlc = 1;
	write(STDIN_FILENO, "\n", 1);
	rl_on_new_line();
	rl_done = 1;
}

static int	write_in_tmp_file(int fd, char *str)
{
	ssize_t	len;
	ssize_t	ret;

	len = ft_strlen(str);
	ret = write(fd, str, len);
	ret += write(fd, "\n", 1);
	if (ret != len + 1)
	{
		print_str_error("write");
		return (0);
	}
	return (1);
}

int	read_heredoc(int fd, char *stop)
{
	char			*str;
	sig_atomic_t	*cntrlc;

	rl_event_hook = heredoc_event;
	signal(SIGINT, heredoc_handler_sigint);
	while (1)
	{
		str = readline(HEREDOC_PROMPT);
		cntrlc = get_cntrlc();
		if (*cntrlc)
			return (completion(str, cntrlc, 0, fd));
		if (!str || !ft_strcmp(str, stop))
			return (completion(str, cntrlc, 1, fd));
		if (!write_in_tmp_file(fd, str))
			return (completion(str, cntrlc, 0, fd));
		free(str);
	}
	return (1);
}

static int	completion(char *str, int *cntrlc, int status, int fd)
{
	*cntrlc = 0;
	rl_done = 0;
	rl_event_hook = NULL;
	if (!str)
		write(STDOUT_FILENO, "\033[1A> ", sizeof("\033[1A> ") - 1);
	signal(SIGINT, SIG_IGN);
	free(str);
	if (close(fd) == -1)
		print_str_error("close");
	return (status);
}
