/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:53:40 by ccartman          #+#    #+#             */
/*   Updated: 2021/05/18 20:48:08 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stddef.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_file
{
	int				fd;
	char			*buf;
	struct s_file	*next;
}				t_file;

int		get_next_line(int fd, char **line);

char	*ft_strcpy(char *dst, const char *src);

char	*ft_strchr(const char *s, int c);

char	*ft_strdup(const char *s);

char	*ft_strjoin_and_free_s1(char *s1, const char *s2);

int		remove_file(t_file **head, int fd);

#endif
