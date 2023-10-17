/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:09:48 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/17 16:45:59 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_gt	*last_ptr(t_gt *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_ptr(t_gt **head, t_gt *new)
{
	t_gt	*tmp;

	if (!head || !new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	tmp = last_ptr(*head);
	tmp->next = new;
}

void	free_ptr(t_gt **head)
{
	t_gt		*tmp;

	while ((*head))
	{
		tmp = *head;
		(*head) = (*head)->next;
		free(tmp->ptr);
		free(tmp);
		tmp = NULL;
	}
}

void	*get_ptr(size_t i, int flag)
{
	void		*ptr;
	static t_gt	*head;
	t_gt		*tmp;

	tmp = NULL;
	if (flag == 1)
	{
		ptr = malloc(i);
		if (!ptr)
			return (NULL);
		tmp = malloc(sizeof(t_gt));
		tmp->ptr = ptr;
		tmp->next = NULL;
		add_ptr(&head, tmp);
		return (ptr); 
	}
	else
		free_ptr(&head);
	return (NULL);
}
