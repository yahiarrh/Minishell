/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exev.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:50:42 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/11 11:02:47 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_cmdsize(t_cmd *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

char	**join_cmds(t_cmd *command)
{
	char	**c;
	int		len;
	int		i;

	i = 0;
	len = ft_cmdsize(command);
	c = malloc(sizeof(char *) * len + 1);
	ft_memset(c, 0, len + 1);
	while (command)
	{
		c[i] = ft_strdup(command->cmd);
		command = command->next;
		i++;
	}
	return (c);
}

static void	ft_kill(t_id **ids)
{
	while (*ids)
	{
		kill((*ids)->id, SIGKILL);
		free(ids);
		*ids = (*ids)->next;
	}
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
	ptr = ft_lstlast(*lst);
	ptr->next = new;
}

static void process(t_env **env, t_args *arg, int falg, t_id **proc)
{
	t_id	*id;
	int		pie[2];
	int		status;

	pipe(pie);
	id = malloc(sizeof(t_id));
	ft_memset(id, 0, sizeof(t_id));
	id->id = fork();
	id_back(proc, id);
	if (!id)
	{
		if (falg)
			dup2(pie[1], arg->fd_out);
		close(pie[0]);
		comm_type(env, join_cmds(arg->cmd), arg, pie);//lfunc D'AMINE
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

	while (arg)
	{
		if (arg->next)
			process(env, arg, 1, &proc);
		else
			process(env, arg, 0, &proc);
		arg = arg->next;
	}
	ft_kill(proc);
}
