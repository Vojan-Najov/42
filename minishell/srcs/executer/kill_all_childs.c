/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_all_childs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:17:24 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/14 13:17:53 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include <signal.h>

void	kill_all_childs(pid_t *pid, int *fdp, int fd)
{
	size_t	i;
	int		ret;

	i = 0;
	while (pid[i] != -1 && pid[i] != 0)
	{
		ret = kill(pid[i], SIGTERM);
		if (ret == -1)
			print_str_error("kill");
		++i;
	}
	close(fdp[0]);
	close(fdp[1]);
	close(fd);
}
