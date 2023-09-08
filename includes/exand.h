/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exand.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:23:41 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/09/08 11:34:07 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
#define EXPAND_H

# include "../libft/libft.h"
# include "../includes/blt_lib.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*expand(t_env **env, char *var);

#endif