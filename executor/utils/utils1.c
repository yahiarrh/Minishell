/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 09:21:13 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/09/26 10:39:23 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	builtin(t_env **env, char **comm)
{
	if (ft_strcmp(comm[0], "pwd") || ft_strcmp(comm[0], "PWD"))
		ft_pwd(env);
	else if (ft_strcmp(comm[0], "echo") || ft_strcmp(comm[0], "ECHO"))
		ft_echo(comm);
	else if (ft_strcmp(comm[0], "env") || ft_strcmp(comm[0], "ENV"))
		ft_env(env);
	else if (ft_strcmp(comm[0], "cd") || ft_strcmp(comm[0], "CD"))
		ft_cd(env, comm[1]);
	else if (ft_strcmp(comm[0], "export"))
		ft_export(env, comm);
	else if (ft_strcmp(comm[0], "unset"))
		ft_unset(env, comm);
	else if (ft_strcmp(comm[0], "exit"))
		ft_exit(comm);
	else
		return (0);
	return (1);
}

void	comm_type(t_env **env, char	**comm)
{
	if (builtin(env, comm))
		return ;
}