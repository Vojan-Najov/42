/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_status_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:28:07 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/17 11:54:36 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell_envp.h"

void	free_exit_status_str(void)
{
	char	**status;

	status = get_exit_status_str_address();
	free(*status);
	*status = NULL;
}
