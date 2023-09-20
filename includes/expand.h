/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:23:41 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/09/20 11:54:33 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

// # include "../libft/libft.h"
// # include "../includes/blt_lib.h"
# include <stdio.h>
# include <stdlib.h>
# include "../minishell.h"
# include <unistd.h>

char	*expand(t_env **env, char *var);

#endif