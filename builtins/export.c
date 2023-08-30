/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:16:02 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/08/30 17:31:39 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blt_lib.h"

static char	*extr_val(char *name)
{
	int	i;

	i = 0;
	while (name[i])
	{
		if (name[i] == '=')
			return(name + i + 1);
		if (name[i] == '+' && name[i + 1] == '=')
			return(name + i + 1);
		i++;
	}
	return (NULL);
}

void	ft_export(t_env **env, char *name)
{
	t_env	*tmp;
	char	*value;

	if (!name)
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
	if (!ft_checkarg(name))
	{
		ft_putstr_fd("bash: export: ", 2);
		ft_putstr_fd(name, 2);
		ft_putstr_fd(" :not a valid identifier\n", 2);
		return ;
	}
	value = extr_val(name);
	if(!value)
	{
		tmp = ft_lstnew(name);
		ft_lstadd_back(env, tmp);
	}
	// else
	// {

	// }
}