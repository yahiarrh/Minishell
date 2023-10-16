/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:16:02 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/16 12:39:07 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*extr_val(char *val)
{
	int	i;

	i = 0;
	while (val[i])
	{
		if (val[i] == '=')
			return (val + i);
		if (val[i] == '+' && val[i + 1] == '=')
			return (val + i);
		i++;
	}
	return (NULL);
}

static int	extr_name(char *name)
{
	int	i;

	i = 0;
	while (name[i])
	{
		if (name[i] == '=')
			return (i);
		if (name[i] == '+' && name[i + 1] == '=')
			return (i);
		i++;
	}
	return (i);
}

static void	pr_env(t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (!tmp->value)
			printf("declare -x %s\n", tmp->name);
		else
			printf("declare -x %s=\"%s\"\n", tmp->name, tmp->value);
		tmp = tmp->next;
	}
}

static void	up_val(t_env **env, char *name, char *n)
{
	t_env	*tmp;
	char	*value;
	char	*v;

	value = extr_val(name);
	tmp = NULL;
	v = NULL;
	if (!ft_getval(env, n))
	{
		tmp = lstnew(n);
		lstadd_back(env, tmp);
	}
	if (value)
	{
		if (*value == '=')
			ft_update(env, n, value + 1);
		else if (*value == '+' && ft_getval(env, n)->value)
			ft_update(env, n, 
				ft_join(ft_getval(env, n)->value, value + 2));
		else
			ft_update(env, n, value + 2);
	}
}

void	ft_export(t_env **env, char **name)
{
	char	*n;
	int		i;

	if (!name[1])
	{
		pr_env(env);
		return ;
	}
	name++;
	while (*name)
	{
		i = extr_name(*name);
		n = ft_sub(*name, 0, i);
		if (!ft_checkarg(n))
		{
			ft_err_msg("export: ", *name,
				" :not a valid identifier\n", 1);
		}
		else
			up_val(env, *name, n);
		name++;
	}
	return ;
}
