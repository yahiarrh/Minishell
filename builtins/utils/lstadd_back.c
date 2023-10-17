/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:39:28 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/17 16:20:32 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_env	*new(char *name, char *val)
{
	t_env	*tmp1;

	tmp1 = malloc(sizeof(t_env));
	tmp1->name = ft_dup(name);
	tmp1->value = ft_dup(val);
	tmp1->next = NULL;
	return (tmp1);
}

void	lstadd_back(t_env **lst, t_env *new)
{
	t_env	*ptr;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ptr = lstlast(*lst);
	ptr->next = new;
}

void	lstdelone(t_env *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->name);
	del(lst->value);
	free (lst);
	lst = NULL;
}
