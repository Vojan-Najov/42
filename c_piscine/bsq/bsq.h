/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:33:54 by ccartman          #+#    #+#             */
/*   Updated: 2021/03/10 21:45:36 by malison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_desc
{
	unsigned int	lines;
	unsigned int	rows;
	char			empty;
	char			obstacle;
	char			full;
}					t_desc;
typedef struct		s_sq
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	sq;
}					t_sq;

void				ft_draws_and_print_map(int fd);
void				ft_output(t_desc *desc, t_sq *rez, unsigned int *matrix);
unsigned int		ft_min(unsigned int a, unsigned int b, unsigned int c);
void				ft_sq_update(t_sq *sq, unsigned int x, unsigned int y, \
					unsigned int s);
t_sq				*ft_find_square(unsigned int *matrix, unsigned int n,\
					unsigned int m);
int					ft_strlen(char *str);
unsigned int		ft_atoi(char *str);
char				*ft_dupx(char *str, int *size);
unsigned int		*ft_read_map(int fd, t_desc *desc);
t_desc				*ft_read_zero_line(int fd, t_desc *desc);
unsigned int		*ft_read_first_line(int fd, t_desc *desc);
unsigned int		*ft_read_other_lines(int fd, t_desc *desc, \
					unsigned int *matrix, char *buf);
int					ft_check_symbs(char ce, char co, char cf);

#endif
