/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:26:28 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/13 14:53:26 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
	i = -1;
	while (envp[++i])
	{
		equ = 0;
		while (envp[i][equ] && envp[i][equ] != '=')
			equ++;
		tmp = get_ptr(sizeof(t_env), 1);
		ft_memset(tmp, 0, sizeof(t_env));
		tmp->name = ft_substr(envp[i], 0, equ);
		if (!ft_cmp(tmp->name, "OLDPWD"))
			tmp->value = NULL;
		else
			tmp->value = getenv(tmp->name);
		lstadd_back(&env, tmp);
	}
	return (env);
}

t_env	*ft_getval(t_env **env, char *name)
{
	t_env	*tmp;

	tmp = *env;
	if (!name)
		return (NULL);
	while (tmp)
	{
		if (!ft_cmp(tmp->name, name))
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

int	ft_checkarg(char *arg)
{
	int	i;

	i = 1;
	if (!ft_isalpha(arg[0]) && arg[0] != '_')
		return (0);
	while (arg[i])
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (0);
		i++;
	}
	return (1);
}
