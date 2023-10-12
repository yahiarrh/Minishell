/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exev.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:50:42 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/12 12:12:29 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// static void	ft_kill(t_id **ids)
// {
// 	while (*ids)
// 	{
// 		kill((*ids)->id, SIGKILL);
// 		free(ids);
// 		*ids = (*ids)->next;
// 	}
// }

static t_id	*idlast(t_id *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

static void	id_back(t_id **lst, t_id *new)
{
	t_id	*ptr;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ptr = idlast(*lst);
	ptr->next = new;
}

static void	process(t_env **env, t_args *arg, int falg, t_id **proc)
{
	t_id	*id;
	int		pie[2];
	// int		status;
	dup2(arg->fd_out, 1);
	dup2(arg->fd_in, 0);
	pipe(pie);
	id = malloc(sizeof(t_id));
	ft_memset(id, 0, sizeof(t_id));
	id->id = fork();
	id_back(proc, id);
	if (!id->id)
	{
		if (falg)
			dup2(pie[1], arg->fd_out);
		close(pie[0]);
		close(arg->fd_out);
		comm_type(env, join_cmds(arg->cmd), 1);
	}
	else
	{
		if (falg)
			dup2(pie[0], arg->fd_in);
		close(pie[1]);
		close(arg->fd_in);
		wait(NULL);
		// waitpid(id->id, &status, 0);
	}
}

void	ft_exec(t_env **env, t_args *arg)
{
	t_id *proc;

	proc = NULL;
	while (arg)
	{
		if (arg->next)
			process(env, arg, 1, &proc);
		else
			process(env, arg, 0, &proc);
		arg = arg->next;
	}
	// ft_kill(&proc);
}
