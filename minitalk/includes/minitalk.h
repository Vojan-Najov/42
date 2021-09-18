#ifndef MINITALK_H
#define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>		////

# define BUFSIZE 512

int		print_args_error(void);

int		print_pid_error(void);

void	print_signal_error(void);

#endif
