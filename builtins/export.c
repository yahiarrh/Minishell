/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:16:02 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/09/03 08:51:22 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blt_lib.h"

static char	*extr_val(char *val)
{
	int	i;

	i = 0;
	while (val[i])
	{
		if (val[i] == '=')
			return(val + i);
		if (val[i] == '+' && val[i + 1] == '=')
			return(val + i);
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
			return(i);
		if (name[i] == '+' && name[i + 1] == '=')
			return(i);
		i++;
	}
	return (i);
}

void	ft_export(t_env **env, char **name)
{
	t_env	*tmp;
	char	*value;
	char	*n;
	int		i;

	if (!name[1])
	{
		tmp = *env;
		while (tmp)
		{
			if (!tmp->value)
				printf("declare -x %s\n",tmp->name);
			else
				printf("declare -x %s=\"%s\"\n",tmp->name, tmp->value);
			tmp = tmp->next;
		}
		return ;
	}
	name++;
	while (*name)
	{
		i = extr_name(*name);
		n = ft_substr(*name, 0, i);
		if (!ft_checkarg(n))
		{
			ft_putstr_fd("bash: export: ", 2);
			ft_putstr_fd(*name, 2);
			ft_putstr_fd(" :not a valid identifier\n", 2);
		}
		else
		{
			value = extr_val(*name);
			if(!ft_getval(env, n))
			{
				tmp = ft_lstnew(n);
				ft_lstadd_back(env, tmp);
			}
			if(value)
			{
				if (*value == '=')
				{
					ft_update(env, n, value + 1);
				}
				else if (*value == '+')
				{
					ft_update(env, n,
						ft_strjoin(ft_getval(env, n)->value, value + 2));
				}
				else
					ft_update(env, n, value);
			}
		}
		name++;
	}
	return ;
}