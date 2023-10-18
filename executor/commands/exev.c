/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exev.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:50:42 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/18 13:11:04 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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

static void	process(t_env **env, t_args *arg)
{
	pid_t	t;
	int		fd[2];
	int		tmp_fd[2];

	pipe(fd);
	comm_type(env, join_cmds(arg->cmd), (t_fd){0, fd[1], fd}, arg);
	arg = arg->next;
	while (arg->next)
	{
		pipe(tmp_fd);
		close(fd[1]);
		comm_type(env, join_cmds(arg->cmd),
			(t_fd){fd[0], tmp_fd[1], tmp_fd}, arg);
		close(fd[0]);
		fd[0] = tmp_fd[0];
		fd[1] = tmp_fd[1];
		arg = arg->next;
	}
	t = comm_type(env, join_cmds(arg->cmd),
			(t_fd){fd[0], STDOUT_FILENO, fd}, arg);
	close(fd[1]);
	close(fd[0]);
	sig_par(t);
	while (wait(NULL) != -1)
		;
}

static void	process1(t_env **env, t_args *arg)
{
	pid_t	id;
	char	**s;

	if (arg->fd_in == -1)
		return ;
	s = join_cmds(arg->cmd);
	if (!s || !*s)
		return ;
	id = fork();
	sig_ch(id);
	if (!id && s[0])
	{
		dup2(arg->fd_out, 1);
		dup2(arg->fd_in, 0);
		if (builtin(env, s, 0))
			exit (g_exit_status);
		sys_comm(env, s);
	}
	sig_par(id);
}

void	ft_exec(t_env **env, t_args *arg)
{
	t_id	*proc;

	proc = NULL;
	if (argsize(arg) == 1 && is_builtin(join_cmds(arg->cmd)[0]))
	{
		if (arg->fd_in == -1)
			return ;
		if (arg->fd_out != 1)
			dup2(arg->fd_out, STDOUT_FILENO);
		builtin(env, join_cmds(arg->cmd), 0);
		return ;
	}
	else if (argsize(arg) == 1)
	{
		process1(env, arg);
		return ;
	}
	else
		process(env, arg);
}
