/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:03:58 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/07 17:45:26 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
			ft_err_msg("bash: unset: ", name[i],
				" :not a valid identifier\n");
		else
		{
			tmp2 = ft_getval(env, name[i]);
			if (tmp2)
			{
				if (!ft_cmp((*env)->name, name[i]))
					*env = (*env)->next;
				else
					tmp = prev(*env, tmp2, name[i]);
				ft_lstdelone(tmp2, free);
				tmp2 = NULL;
			}
		}
		i++;
	}
}
