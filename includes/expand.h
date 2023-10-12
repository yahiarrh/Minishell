/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:23:41 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/12 12:11:11 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "../minishell.h"
# include "parcing.h"

char	*expand(t_env **env, char *var);
t_cmd	*filtre_exp(t_env **env, t_token *token);

#endif