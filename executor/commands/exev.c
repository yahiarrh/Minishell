/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exev.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:50:42 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/11 18:42:12 by yrrhaibi         ###   ########.fr       */
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

static int	argsize(t_args *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

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

static void process(t_env **env, t_args *arg, int falg, t_id **proc)
{
	t_id	*id;
	int		fd[2];

	id = malloc(sizeof(t_id));
	ft_memset(id, 0, sizeof(t_id));

}
static void process1(t_env **env, t_args *arg, t_id **proc)
{
	t_id	*id;
	// int		status;

	dup2(arg->fd_out, 1);
	dup2(arg->fd_in, 0);
	id = malloc(sizeof(t_id));
	ft_memset(id, 0, sizeof(t_id));
	id->id = fork();
	id_back(proc, id);
	if (!id->id)
		comm_type(env, join_cmds(arg->cmd), 1);
	else
	{
		wait(NULL);
		// waitpid(id->id, &status, 0);
	}
}

void	ft_exec(t_env **env, t_args *arg)
{
	t_id *proc;

	proc = NULL;
	if (argsize(arg) == 1 && builtin(env, join_cmds(arg->cmd)))
		return ;
	else if (argsize(arg) == 1)
	{
		process1(env, arg, &proc);
		return ;
	}
	else
		process(env, arg,)
	// ft_kill(&proc);
}
