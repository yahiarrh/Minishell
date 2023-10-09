/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exev.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:59:39 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/09 18:37:46 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEV_H
# define EXEV_H

# include "../minishell.h"

typedef struct s_id
{
    int id;
    struct s_id *next;
}t_id;

void    exec_comm(t_env **env, char **comm, char **path);
void	comm_type(t_env **env, char	**comm, t_args *arg, int *pie);
#endif