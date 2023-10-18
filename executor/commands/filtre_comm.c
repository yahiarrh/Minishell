/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filtre_comm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 09:21:13 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/18 13:12:11 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

bool	is_builtin(char *comm)
{
	if (!ft_cmp(comm, "pwd"))
		return (true);
	else if (!ft_cmp(comm, "echo"))
		return (true);
	else if (!ft_cmp(comm, "env"))
		return (true);
	else if (!ft_cmp(comm, "cd"))
		return (true);
	else if (!ft_cmp(comm, "export"))
		return (true);
	else if (!ft_cmp(comm, "unset"))
		return (true);
	else if (!ft_cmp(comm, "exit"))
		return (true);
	return (false);
}

void	sys_comm(t_env **env, char **comm)
{
	char	**path;
	t_env	*tmp;

	tmp = ft_getval(env, "PATH");
	if (access(comm[0], X_OK) && !tmp)
	{
		ft_err_msg(NULL, comm[0], FILE_ERR, 127);
		exit(127);
	}
	if (!tmp)
		path = ft_split(PATH, ':');
	else
		path = ft_split(tmp->value, ':');
	exec_comm(env, comm, path);
}

int	builtin(t_env **env, char **comm, bool f)
{
	g_exit_status = 0;
	if (!ft_cmp(comm[0], "pwd"))
		ft_pwd();
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
		ft_exit(comm, f);
	else
		return (0);
	return (1);
}

void	sig_par(pid_t p)
{
	int	status;

	if (wait(&status) == p)
	{
		if (WIFEXITED(status))
			g_exit_status = WEXITSTATUS(status);
		if (WIFSIGNALED(status))
			g_exit_status = 128 + WTERMSIG(status);
	}
	if (status == SIGINT)
		write(1, "\n", 2);
	if (status == SIGQUIT)
		write(1, "Quit : 3\n", 10);
}

pid_t	comm_type(t_env **env, char	**comm, t_fd fd, t_args *arg)
{
	pid_t	tmp;

	tmp = 0;
	if (arg->fd_in == -1)
		return (tmp);
	if (!comm || !*comm)
		return (tmp);
	if (arg->fd_in)
		fd.fd_in = arg->fd_in;
	if (arg->fd_out != 1)
		fd.fd_out = arg->fd_out;
	tmp = fork();
	sig_ch(tmp);
	if (!tmp)
	{
		dup2(fd.fd_out, 1);
		dup2(fd.fd_in, 0);
		close(fd.fd_toclose[1]);
		close(fd.fd_toclose[0]);
		if (builtin(env, comm, 1))
			exit (g_exit_status);
		sys_comm(env, comm);
	}
	return (tmp);
}
