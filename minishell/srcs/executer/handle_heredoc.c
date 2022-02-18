/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:37:29 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/15 17:52:22 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static int	handle_heredoc(t_redirect *redirect);

static int	*get_heredoc_num_address(void);

static char	*get_filename(int num);

int	handle_heredocuments(t_command **cmd)
{
	size_t	i;
	size_t	j;
	int		*num_add;

	i = -1;
	while (cmd[++i])
	{
		j = -1;
		while (cmd[i]->redirect[++j])
		{
			if (cmd[i]->redirect[j]->type & REDIRECT_HEREDOC)
			{
				if (!handle_heredoc(cmd[i]->redirect[j]))
					return (0);
			}
		}
	}
	num_add = get_heredoc_num_address();
	*num_add = 0;
	return (1);
}

static int	*get_heredoc_num_address(void)
{
	static int	num;

	return (&num);
}

static int	handle_heredoc(t_redirect *redirect)
{
	int		fd;
	int		*num_add;
	char	*filename;

	num_add = get_heredoc_num_address();
	filename = get_filename(*num_add);
	if (!filename)
		return (0);
	++*num_add;
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
	{
		print_str_error(filename);
		return (0);
	}
	if (!read_heredoc(fd, redirect->name))
		return (0);
	free(redirect->name);
	redirect->name = filename;
	if (close (fd) == -1)
		print_str_error(filename);
	return (1);
}

static char	*get_filename(int num)
{
	char	*tmp;
	char	*filename;

	tmp = ft_itoa(num);
	if (!tmp)
	{
		print_str_error("malloc");
		return (NULL);
	}
	filename = ft_strjoin(HEREDOC_TMP_FILE, tmp);
	free(tmp);
	if (!filename)
		print_str_error("malloc");
	return (filename);
}

/*
static int	read_heredoc(int fd, char *stop)
{
	char	*str;
	ssize_t	len;
	ssize_t	ret;

	while (1)
	{
		str = readline(HEREDOC_PROMPT);
		if (!str)
			break ;
		if (!ft_strcmp(str, stop))
		{
			free(str);
			break ;
		}
		len = ft_strlen(str);
		ret = write(fd, str, len);
		ret += write(fd, "\n", 1);
		if (ret != len + 1)
		{
			free(str);
			return (0);
		}
		free(str);
	}
	return (1);
}
*/
