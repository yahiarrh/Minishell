/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exev.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:59:39 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/12 12:11:31 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEV_H
# define EXEV_H

# include "../minishell.h"

typedef struct s_id
{
	pid_t		id;
	struct s_id	*next;
}t_id;

void	ft_exec(t_env **env, t_args *arg);
void	exec_comm(t_env **env, char **comm, char **path);
void	comm_type(t_env **env, char	**comm, int flag);
#endif