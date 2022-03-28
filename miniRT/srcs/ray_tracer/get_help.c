/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:41:09 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/25 22:03:58 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ray_tracer.h"

void	get_help(void)
{
	write(STDOUT_FILENO, g_help_msg, sizeof(g_help_msg) - 1);
}	
