/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exev.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:59:39 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/12 16:16:37 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEV_H
# define EXEV_H

# include "../minishell.h"

typedef struct s_id
{
	pid_t		id;
	struct s_id *next;
}t_id;

typedef struct s_fd
{
	int fd_in;
	int fd_out;
	int fd_toclose;
}t_fd;

int		builtin(t_env **env, char **comm);
void	ft_exec(t_env **env, t_args *arg);
void	exec_comm(t_env **env, char **comm, char **path);
pid_t	comm_type(t_env **env, char	**comm, t_fd fd, t_args *arg);
void	sys_comm(t_env **env, char **comm);
#endif