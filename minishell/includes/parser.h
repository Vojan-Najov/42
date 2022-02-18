/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:10:51 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/15 18:42:09 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>

# include "libft.h"
# include "minishell_envp.h"
# include "minishell_errors.h"
# include "minishell.h"

# define PREPARSE_SUCCESS 0
# define PREPARSE_ERROR 1
# define PREPARSE_BLANK 2

# define PARSE_SUCCESS 1
# define PARSE_ERROR 0

static const char	g_quote_err[] = \
"minishell: syntax error is unclosed quote\n";

static const char	g_token_err[] = \
"minishell: syntax error near unexpected token '";

int		preparse(const char *str);

int		ft_isblank(char c);

int		ft_istoken(const char *str, int flag);

int		get_fd(t_list *lst);

size_t	count_commands(t_list **lsts);

size_t	count_redirects(t_list *lst);

size_t	count_args(t_list *lst);

int		split_into_words(const char *str, t_list **lst);

int		split_into_tokens(t_list **lst);

void	set_words_flags(t_list *lst);

int		check_tokens(t_list **lst);

int		malloc_list_error(t_list **lst);

t_list	**split_into_commands(t_list **lst);

t_cmds	*init_cmds(t_list **lsts);

int		init_command(t_command **command, t_list **lst);

void	free_redirect(t_redirect **rdr);

int		expansion_words(t_list **lst);

int		expansion_word(char **ptr);

size_t	new_word_length(char *str);

int		ft_notadd(char *str, int expan);

#endif
