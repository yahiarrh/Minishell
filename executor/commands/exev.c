/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exev.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:50:42 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/12 17:11:46 by yrrhaibi         ###   ########.fr       */
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

static void process(t_env **env, t_args *arg)
{
	pid_t	t;
	int		fd[2];
	int		tmp_fd[2];

	pipe(fd);
	comm_type(env, join_cmds(arg->cmd), (t_fd){ 0, fd[1], fd[1]}, arg);
	arg = arg->next;
	while (arg->next)
	{
		pipe(tmp_fd);
		comm_type(env, join_cmds(arg->cmd), (t_fd){ fd[0], tmp_fd[1], tmp_fd[1]}, arg);
		// close(fd[0]);
		// close(fd[1]);
		fd[0] = tmp_fd[0];
		fd[1] = tmp_fd[1];
		arg = arg->next;
	}
	t = comm_type(env, join_cmds(arg->cmd), (t_fd){ fd[0], STDOUT_FILENO, fd[1]}, arg);
	waitpid(t, NULL, 0);
}
static void process1(t_env **env, t_args *arg)
{
	pid_t	id;
	// int		status;

	id = fork();
	if (!id)
	{
		dup2(arg->fd_out, 1);
		dup2(arg->fd_in, 0);
		sys_comm(env, join_cmds(arg->cmd));
	}
	else
		wait(NULL);
}

void	ft_exec(t_env **env, t_args *arg)
{
	t_id *proc;

	proc = NULL;
	if (argsize(arg) == 1 && builtin(env, join_cmds(arg->cmd)))
		return ;
	else if (argsize(arg) == 1)
	{
		process1(env, arg);
		return ;
	}
	else
		process(env, arg);
	// ft_kill(&proc);
}
