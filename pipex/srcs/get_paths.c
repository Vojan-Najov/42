#include "pipex.h"

static int	search_path(char **envp);

static char	**add_slash(char **paths);

char	**get_paths(char **envp)
{
	int		i;
	char	**paths;

	i = search_path(envp);
	if (i == -1)
		return (NULL);
	paths = ft_split(&envp[i][5], ':');
	if (!paths)
	{	
		write(STDERR_FILENO, g_mem_err, sizeof(g_mem_err) - 1);
		return (NULL);
	}
	paths = add_slash(paths);
	return (paths);
}

static int	search_path(char **envp)
{
	char	*str;
	size_t	len;
	int		i;

	i = 0;
	str = "PATH=";
	len = ft_strlen(str);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], str, len) == 0)
			return (i);
		++i;
	}
	return (-1);
}

static char	**add_slash(char **paths)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (paths[i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(paths[i], "/");
		free(tmp);
		if (!paths[i])
		{
			j = 0;
			while (paths[j] || j == i)
			{
				free(paths[j]);
				++j;
			}
			free(paths);
			write(STDERR_FILENO, g_mem_err, sizeof(g_mem_err) - 1);
			return (NULL);
		}
		++i;
	}
	return (paths);
}
