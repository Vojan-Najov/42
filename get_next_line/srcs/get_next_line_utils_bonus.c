/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:20:37 by ccartman          #+#    #+#             */
/*   Updated: 2021/05/17 20:26:06 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strcpy(char *dst, char const *src)
{
	char	*d;

	d = dst;
	while (*src)
		*d++ = *src++;
	*d = '\0';
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	char	smb;

	smb = (char) c;
	while (*s)
		if (*s++ == smb)
			return ((char *)--s);
	if (smb == '\0')
		return ((char *) s);
	else
		return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char		*dup;
	const char	*str;

	str = s1;
	while (*str)
		++str;
	dup = (char *) malloc(sizeof(*dup) * (str - s1 + 1));
	if (dup)
		ft_strcpy(dup, s1);
	return (dup);
}

char	*ft_strjoin_and_free_s1(char *s1, const char *s2)
{
	char		*str;
	char		*str1;
	const char	*str2;
	size_t		s1_len;
	size_t		s2_len;

	str1 = s1;
	while (*str1)
		++str1;
	str2 = s2;
	while (*str2)
		++str2;
	s1_len = str1 - s1;
	s2_len = str2 - s2;
	str = (char *) malloc(sizeof(*str) * (s1_len + s2_len + 1));
	if (str)
	{
		ft_strcpy(str, s1);
		ft_strcpy(str + s1_len, s2);
	}
	free(s1);
	return (str);
}

int	remove_file(t_file **head, int fd)
{
	t_file	*tmp;

	while (*head)
	{
		if ((*head)->fd == fd)
		{
			tmp = *head;
			*head = (*head)->next;
			free(tmp->buf);
			free(tmp);
		}
		else
			head = &(*head)->next;
	}
	return (-1);
}
