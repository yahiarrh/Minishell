/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_comm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:21:18 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/02 08:57:02 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char *find_path(char *comm, char **path)
{
	char	*tmp;

	while (*path)
	{
		tmp = ft_strjoin(*path, comm);
		if (!access(tmp, X_OK))
			return (tmp);
		free(tmp);
		path++;
	}
	return (NULL);
}

void    exec_comm(t_env **env, char **comm, char **path)
{
	char    *rpat;

	rpat = find_path(comm[0], path);
	execve(rpat, comm, env);
}