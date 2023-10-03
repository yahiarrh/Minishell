/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:23:41 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/03 15:50:47 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

// # include "../libft/libft.h"
// # include "../includes/blt_lib.h"
# include "../minishell.h"

char	*expand(t_env **env, char *var);
t_cmd *filtre_exp(t_env **env, t_token *token);

#endif