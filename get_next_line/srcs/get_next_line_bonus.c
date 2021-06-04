/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:52:49 by ccartman          #+#    #+#             */
/*   Updated: 2021/05/17 20:31:12 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char		*check_buffer(t_file *file, char **line);

static int		read_file_until_nl(t_file *file, char **line);

static t_file	*new_file(int fd);

static t_file	*get_file(t_file **head, int fd);

int	get_next_line(int fd, char **line)
{
	static t_file	*head;
	t_file			*file;
	char			*ptr_nl;
	int				n_read;

	file = get_file(&head, fd);
	if (!file)
		return (-1);
	ptr_nl = check_buffer(file, line);
	if (!ptr_nl && *line)
		n_read = read_file_until_nl(file, line);
	if (!*line || n_read == -1)
	{
		if (*line)
			free(*line);
		*line = NULL;
		return (remove_file(&head, fd));
	}
	if (n_read > 0 || *file->buf || ptr_nl)
		return (1);
	remove_file(&head, fd);
	return (0);
}

static char	*check_buffer(t_file *file, char **line)
{
	char	*ptr_nl;

	ptr_nl = ft_strchr(file->buf, '\n');
	if (ptr_nl)
	{
		*ptr_nl = '\0';
		*line = ft_strdup(file->buf);
		++ptr_nl;
		ft_strcpy(file->buf, ptr_nl);
	}
	else
	{
		*line = ft_strdup(file->buf);
		*file->buf = '\0';
	}
	return (ptr_nl);
}

static int	read_file_until_nl(t_file *file, char **line)
{
	int		n_read;
	char	*ptr_nl;

	n_read = read(file->fd, file->buf, BUFFER_SIZE);
	while (n_read > 0)
	{
		*(file->buf + n_read) = '\0';
		ptr_nl = ft_strchr(file->buf, '\n');
		if (ptr_nl)
		{
			*ptr_nl = '\0';
			*line = ft_strjoin_and_free_s1(*line, file->buf);
			++ptr_nl;
			ft_strcpy(file->buf, ptr_nl);
			break ;
		}
		else
		{	
			*line = ft_strjoin_and_free_s1(*line, file->buf);
			*file->buf = '\0';
		}
		n_read = read(file->fd, file->buf, BUFFER_SIZE);
	}
	return (n_read);
}

static t_file	*new_file(int fd)
{
	t_file	*file;

	file = (t_file *) malloc(sizeof(*file));
	if (file)
	{
		file->fd = fd;
		file->buf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!file->buf)
		{
			free(file);
			return (NULL);
		}
		*file->buf = '\0';
		file->next = NULL;
	}
	return (file);
}

static t_file	*get_file(t_file **head, int fd)
{
	while (*head)
	{
		if ((*head)-> fd == fd)
			return (*head);
		head = &(*head)->next;
	}
	*head = new_file(fd);
	return (*head);
}
