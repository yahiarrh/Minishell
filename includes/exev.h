/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exev.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:59:39 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/07 16:16:50 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEV_H
# define EXEV_H

# include "../minishell.h"

void    exec_comm(t_env **env, char **comm, char **path);
void	comm_type(t_env **env, char	**comm, int *pipe);
#endif