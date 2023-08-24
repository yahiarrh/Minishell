/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 08:58:40 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/08/24 14:55:22 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blt_lib.h"

t_env	*ft_getenv(char **envp)
{
	t_env	*env;
	t_env	*tmp;
	int		i;
	int		j;
	int		equ;

	i = 0;
	env = NULL;
	while (envp[i])
		i++;
	i = 0;
	while (envp[i])
	{
		equ = 0;
		j = 0;
		while (envp[i][equ] && envp[i][equ] != '=')
			equ++;
		tmp = malloc(sizeof(t_env));
		tmp->name = ft_substr(envp[i], 0, equ);
		tmp->value = getenv(tmp->name);
		ft_lstadd_back(&env, tmp);
		i++;
	}	
	return env;
}