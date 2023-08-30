/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:03:58 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/08/30 12:39:29 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blt_lib.h"

void	ft_unset(t_env **env, char *name)
{
	t_env	*tmp;
	t_env	*tmp2;

	if (!ft_checkarg(name))
	{
		ft_putstr_fd("bash: unset: ", 2);
		ft_putstr_fd(name, 2);
		ft_putstr_fd(" :not a valid identifier\n", 2);
		return ;
	}
	if(!(tmp2 = ft_getval(env, name)))
		return ;
	tmp = *env;
	if(!ft_strcmp(tmp->name, name))
		*env = tmp->next;
	else
	{
		while (ft_strcmp(tmp->next->name, name))
			tmp = tmp->next;
		tmp->next = tmp2->next;
	}
	ft_lstdelone(tmp2, free);
	tmp2 = NULL;
}