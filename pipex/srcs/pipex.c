/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:38:30 by ccartman          #+#    #+#             */
/*   Updated: 2022/01/17 20:35:31 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	search_path(char *str);

int	main(int argc, char **argv, char **env)
{
	char	**paths;
	int		save0;
	int		save1;
	int		fd_input;
	int		fd_output;
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	(void) argc;
	(void) argv;
	while (*env)
	{
		if (search_path(*env))
			break ;
		++env;
	}
	if (*env == NULL)
		return (1);
	paths = ft_split(&(*env)[5], ':');
	while (*paths)
	{
		printf("%s\n", *paths);
		++paths;
	}

	/*	stdin */
	if (access(argv[1], R_OK))
	{
		perror(argv[1]);
		// completion();
	}
	fd_input = open(argv[1], O_RDONLY);
	if (fd[0] == -1)
	{
		perror(argv[1]);
		//completion();
	}
	save0 = dup(STDIN_FILENO);
	dup2(fd_input, STDIN_FILENO);
	close(fd_input);

	/*	stdout */
	if (!access(argv[2], F_OK) && access(argv[2], W_OK))
	{
		perror(argv[2]); //maybe need unlinking and creating output file
		// completion;
	}
	fd_output = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666 /*- umask*/);
	if (fd[1] == -1)
	{
		perror(argv[2]);
		//completion();
	}
	save1 = dup(STDOUT_FILENO);
	dup2(fd_output, STDOUT_FILENO);
	close(fd_output);
	
	/* pipe time */
	pipe(fd);
	pid1 = fork();
	if (pid1 == -1)
	{
		perror("fork");
		// completion();
	}
	if (pid1 == 0)
	{
		close(fd[0]);
		//
	}
	pid2 = fork();
	if (pid2 == -1)
	{
		perror("fork");
		//completion
	}
	if (pid2 == 0)
	{
		close(fd[1]);
		//
	}
	close(fd[0]);
	close(fd[1]);

	/* return old fds */
	dup2(save0, STDIN_FILENO);
	close(save0);
	dup2(save1, STDOUT_FILENO);
	close(save1);

	return (0);
}

static int	search_path(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len < 5)
		return (0);
	if (str[0] == 'P' && str[1] == 'A' && str[2] == 'T' && str[3] == 'H' && \
															str[4] == '=')
		return (1);
	return (0);
}

/* 	FORK

 * int	p;
 * p = fork();
 * if (p == -1)
 * {
 * 		//
 * }
 * else if (p == 0)
 * {
 * 		// child
 * }
 * else
 * {
 * 		// parent
 * 	}
 */
/*	OPEN
// < << input file
fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
	perror("open");
	exit(EXIT_FAILURE);
}
// > output file
fd = open(argv[4], O_WRONLY | O_CREATE | O_TRUNK, S_IRUSR | S_IWUSR);
if (fd == -1)
{
	perror("open");
	exit(EXIT_FAILURE);
}// >> output file
fd = open(argv[4], O_WRONLY | O_APPEND | O_CREATE, S_IRUSR | S_IWUSR);
if (fd == -1)
{
	perror("open");
	exit(EXIT_FAILURE);
}
// CLOSE ERROR
ret = close(fd);
if (ret == -1)
{
	perror("close");
	exit(EXIT_FAILURE);
}
*/

