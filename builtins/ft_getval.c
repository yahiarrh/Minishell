/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:26:28 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/08/29 17:04:31 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blt_lib.h"

t_env	*ft_getenv(char **envp)
{
	t_env	*env;
	t_env	*tmp;
	int		i;
	int		equ;

	i = 0;
	env = NULL;
	while (envp[i])
		i++;
	i = 0;
	while (envp[i])
	{
		equ = 0;
		while (envp[i][equ] && envp[i][equ] != '=')
			equ++;
		tmp = malloc(sizeof(t_env));
		tmp->name = ft_substr(envp[i], 0, equ);
		if (!ft_strcmp(tmp->name, "OLDPWD"))
			tmp->value = NULL;
		else
			tmp->value = getenv(tmp->name);
		ft_lstadd_back(&env, tmp);
		i++;
	}	
	return env;
}

t_env *ft_getval(t_env **env, char *name)
{
	t_env	*tmp;

	tmp = *env;

	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_update(t_env **env, char *name, char *nv)
{
	t_env	*tmp;

	tmp = ft_getval(env, name);
	tmp->value = nv;
}