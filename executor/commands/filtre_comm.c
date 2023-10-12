/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filtre_comm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 09:21:13 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/12 17:07:35 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	sys_comm(t_env **env, char **comm)
{
	char	**path;
	t_env	*tmp;

	tmp = ft_getval(env, "PATH");
	if (!tmp)
		tmp->value = PATH;
	path = ft_split(tmp->value, ':');
	exec_comm(env, comm, path);
}

int	builtin(t_env **env, char **comm)
{
	if (!ft_cmp(comm[0], "pwd"))
		ft_pwd(env);
	else if (!ft_cmp(comm[0], "echo"))
		ft_echo(comm);
	else if (!ft_cmp(comm[0], "env"))
		ft_env(env);
	else if (!ft_cmp(comm[0], "cd"))
		ft_cd(env, comm[1]);
	else if (!ft_cmp(comm[0], "export"))
		ft_export(env, comm);
	else if (!ft_cmp(comm[0], "unset"))
		ft_unset(env, comm);
	else if (!ft_cmp(comm[0], "exit"))
		ft_exit(comm);
	else
		return (0);
	return (1);
}

pid_t	comm_type(t_env **env, char	**comm, t_fd fd, t_args *arg)
{
	pid_t	tmp;

	if (arg->fd_in)
		fd.fd_in = arg->fd_in;
	if (arg->fd_out != 1)
		fd.fd_out = arg->fd_out;
	tmp = fork();
	if (!tmp)
	{
		dup2(fd.fd_out, 1);
		dup2(fd.fd_in, 0);
		builtin(env, comm);
		sys_comm(env, comm);
	}
	else
	{
		wait(NULL);
		close(fd.fd_toclose);
	}
	return(tmp);
}