#include "get_next_line.h"

static void	free_ptr(char **str);

static char	*check_buffer(char *buf, char **line);

static int	read_until_nl(char *buf, char **line);

static void	ft_strjoin_and_free_src(char **src, const char *str);

static char *ft_strdup(const char *str);

static char	*ft_strchr(const char *s, int c);

static char	*ft_strcpy(char *dst, const char *src);

static size_t	ft_strlen(const char *str);

int	get_next_line(char **line)
{
	static char	*buf;
	char		*ptr_nl;
	int			n_read;

	n_read = 0;
	if (!buf)
	{
		buf = (char *) malloc(sizeof(char) * (BUF_SIZE + 1));
		if (!buf)
			return (-1);
		*buf = '\0';
	}
	ptr_nl = check_buffer(buf, line);
	if (*line && !ptr_nl)
		n_read = read_until_nl(buf, line);
	if (!*line || n_read == -1)
	{
		free_ptr(line);
		free_ptr(&buf);
		return (-1);
	}
	if (ptr_nl || n_read > 0 || *buf || **line)
		return (1);
	free_ptr(&buf);
	return (0);
}

static void	free_ptr(char **str)
{
	free(*str);
	*str = NULL;
}

static char	*check_buffer(char *buf, char **line)
{
	char	*ptr_nl;

	ptr_nl = ft_strchr(buf, '\n');
	if (ptr_nl)
	{
		*ptr_nl = '\0';
		*line = ft_strdup(buf);
		ft_strcpy(buf, ptr_nl + 1);
	}
	else
	{
		*line = ft_strdup(buf);
		*buf = '\0';
	}
	return (ptr_nl);
}

static int	read_until_nl(char *buf, char **line)
{
	int		n_read;
	char	*ptr_nl;

	n_read = read(STDIN_FILENO, buf, BUF_SIZE);
	while (n_read > 0)
	{
		buf[n_read] = '\0';
		ptr_nl = ft_strchr(buf, '\n');
		if (ptr_nl)
		{
			*ptr_nl = '\0';
			ft_strjoin_and_free_src(line, buf);
			ft_strcpy(buf, ptr_nl + 1);
			break ;
		}
		else
		{
			ft_strjoin_and_free_src(line, buf);
			*buf = '\0';
		}
		n_read = read(STDIN_FILENO, buf, BUF_SIZE);
	}
	return (n_read);
}

static void	ft_strjoin_and_free_src(char **src, const char *str)
{
	char	*tmp;
	size_t	len1;
	size_t	len2;

	tmp = *src;
	len1 = ft_strlen(*src);
	len2 = ft_strlen(str);
	*src = (char *) malloc(sizeof(char) * (len1 + len2 + 1));
	if (*src)
	{
		ft_strcpy(*src, tmp);
		ft_strcpy(*src + len1, str);
	}
	free(tmp);
}

static char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(str);
	dup = (char *) malloc(sizeof(char) * (len + 1));
	if (dup)
		ft_strcpy(dup, str);
	return (dup);
}

static size_t	ft_strlen(const char *str)
{
	char	*s;

	s = (char *) str;
	while (*s)
		++s;
	return (s - str);
}

static char	*ft_strcpy(char *dst, const char *src)
{
	char	*d;

	d = dst;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (d);
}

static char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char) *s == (unsigned char) c)
			return ((char *) s);
		++s;
	}
	if ((unsigned char) *s == (unsigned char) c)
			return ((char *) s);
	return (NULL);
}
