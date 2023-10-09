/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exev.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:50:42 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/07 16:16:58 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_exec(t_env **env, t_args *arg)
{
	char	**comm;
	int		id;
	int		pie[2];

	id = fork();
	pipe(pie);
	comm = NULL;
	while (arg)
	{
		if (!id)
			comm_type(env, comm, pie);
		else
			waitpid(-1, NULL, 0);
		arg = arg->next;
	}
		wait(NULL);
}
