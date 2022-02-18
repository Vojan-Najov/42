/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:09:47 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/17 17:18:48 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stddef.h>

# define ARGUMENT 			0b00000001
# define PIPELINE 			0b00000010
# define REDIRECT 			0b00000100
# define REDIRECT_INPUT 	0b00001000
# define REDIRECT_OUTPUT 	0b00010000
# define REDIRECT_HEREDOC 	0b00100000
# define REDIRECT_APPEND 	0b01000000
# define SIMPLE_COMMAND		0b10000000

static const char	g_shell_name[] = "minishell: ";

static const char	g_prompt[] = "$> ";

typedef struct s_redirect
{
	int		type;
	int		fd;
	char	*name;
}			t_redirect;

typedef struct s_command
{
	char		**argv;
	t_redirect	**redirect;
}				t_command;

typedef struct s_cmds
{
	int			type;
	t_command	**command;
}				t_cmds;

int		prepare_env(char **envp);

t_cmds	*parse(const char *str);

void	execution(t_cmds *cmds);

void	free_cmds(t_cmds *cmds);

void	free_str_tab(char **tab);

size_t	mas_size(char **s);

void	std_signals(void);

void	prepare_signals(void);

#endif
