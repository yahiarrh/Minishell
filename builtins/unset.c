/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:03:58 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/18 09:48:53 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_upexp(t_env **env, char *name, char *nv, int flag)
{
	t_env	*tmp;

	tmp = ft_getval(env, name);
	if (tmp->value)
		free(tmp->value);
	tmp->value = ft_dup(nv);
	if (flag)
		free(nv);
}

static t_env	*prev(t_env *tmp, t_env *tmp2, char *name)
{
	while (ft_cmp(tmp->next->name, name))
		tmp = tmp->next;
	tmp->next = tmp2->next;
	return (tmp);
}

void	ft_unset(t_env **env, char **name)
{
	t_env	*tmp;
	t_env	*tmp2;
	int		i;

	i = 0;
	while (name[i])
	{
		if (!ft_checkarg(name[i]))
			ft_err_msg("unset: ", name[i],
				" :not a valid identifier\n", 1);
		else
		{
			tmp2 = ft_getval(env, name[i]);
			if (tmp2)
			{
				if (tmp2 == *env)
					*env = (*env)->next;
				else
					tmp = prev(*env, tmp2, name[i]);
				lstdelone(tmp2, free);
				tmp2 = NULL;
			}
		}
		i++;
	}
}
