/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:26:28 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/08/24 15:35:03 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blt_lib.h"

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