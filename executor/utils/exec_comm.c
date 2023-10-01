/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_comm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:21:18 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/01 11:56:03 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char *find_path(char *comm, char **path)
{
	
}

void    exec_comm(t_env **env, char **comm, char **path)
{
	char    *rpat;

	rpat = find_path(comm[0], path);
}