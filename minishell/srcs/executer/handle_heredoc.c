/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:37:29 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/20 14:58:27 by ccartman         ###   ########.fr       */
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
	{
		if (unlink(filename) == -1)
			print_str_error(filename);
		free(filename);
		return (0);
	}
	free(redirect->name);
	redirect->name = filename;
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
	filename = ft_strjoin(HRDC_TMPFILE, tmp);
	free(tmp);
	if (!filename)
		print_str_error("malloc");
	return (filename);
}
