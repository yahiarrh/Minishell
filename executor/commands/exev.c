/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exev.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:50:42 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/09 18:38:36 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void process(t_env **env, t_args *arg, int falg)
{
	int		id;
	int		pie[2];
	int		status;

	pipe(pie);
	id = fork();
	if (!id)
	{
		if (falg)
			dup2(pie[1], arg->fd_out);
		close(pie[0]);
		comm_type(env, NULL, arg, pie);//lfunc D'AMINE
	}
	else
	{
		dup2(pie[0], arg->fd_in);
		close(pie[1]);
		waitpid(id, &status, 0);
	}
}

void	ft_exec(t_env **env, t_args *arg)
{
	t_id *proc;
	//jme3 l'id's dprocesses
	while (arg)
	{
		if (arg->next)
			process(env, arg, 1);
		else
			process(env, arg, 0);
		arg = arg->next;
	}
}
