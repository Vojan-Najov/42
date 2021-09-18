#include "minitalk.h"

static const char	g_args_error[] = "Usage: ./client [server's pid] [\"message string\"]\n";

static const char	g_pid_error[] = "Server's PID incorrect.\n";

static const char	g_sig_error[] = "Signal ERROR!\n";

int	print_args_error();

int	print_pid_error();

void	print_signal_error();

int	ft_getpid(char *str);

void	contact_server(pid_t spid, char *msg);

int	main(int argc, char **argv)
{
	pid_t	spid;

	if (argc != 3)
		return (print_args_error());
	spid = ft_getpid(argv[1]);
	if (spid <= 0)
		return (print_pid_error());
	contact_server(spid, argv[2]);
	return (0);
}

void	contact_server(pid_t spid, char *msg)
{
	int	b;
	int	ret;

	while (1)
	{
		b = 0x80;
		while (b)
		{
			if (*msg & b)
				ret = kill(spid, SIGUSR2);
			else
				ret = kill(spid, SIGUSR1);
			if (ret == -1)
			{
				print_signal_error();
				exit(EXIT_FAILURE);
			}
			b >>= 1;
			usleep(1000);
		}
		if (!*msg)
			break ;
		++msg;
	}
}

int	ft_getpid(char *str)
{
	int	n;
	char *s;

	s = str - 1;
	while (*++s)
		if (*s < '0' || *s > '9')
			return (-1);
	while (*str == '0')
		++str;
	n = 0;
	while (*str)
	{
		n *= 10;
		n += *str - '0';
		++str;
	}
	if (kill(n, 0) == -1)
		return (-1);
	return (n);
}

int	print_args_error()
{
	write(STDERR_FILENO, g_args_error, sizeof(g_args_error));
	return (1);
}

int	print_pid_error()
{
	write(STDERR_FILENO, g_pid_error, sizeof(g_pid_error));
	return (2);
}

void	print_signal_error()
{
	write(STDERR_FILENO, g_sig_error, sizeof(g_sig_error));
}
