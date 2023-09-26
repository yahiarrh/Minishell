/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:54:40 by msaidi            #+#    #+#             */
/*   Updated: 2023/09/26 13:42:46 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

t_args	*last_token(t_args *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	arg_back(t_args **lst, t_args *new)
{
	t_args	*node;


	if (!new || !lst)
		return ;
	if (*lst)
	{
		node = last_token(*lst);
		node->next = new;
	}
	else
		*lst = new;
}

t_args  *parcing(t_token *token)
{
	t_args  *head;

	head = NULL;
	if (!token)
		return (NULL);
	while (token)
	{
		if (token->type == WORD)
			arg_back(&head, new_arg(token));
	}
	return (head);
}
