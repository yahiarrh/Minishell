/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exev.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:59:39 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/01 11:49:25 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEV_H
# define EXEV_H

// # include "../libft/libft.h"
// # include <stdio.h>
// # include <stdlib.h>
// # include <unistd.h>
# include "../minishell.h"

void    exec_comm(t_env **env, char **comm, char **path);

#endif