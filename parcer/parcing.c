/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:54:40 by msaidi            #+#    #+#             */
/*   Updated: 2023/10/03 14:54:24 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parcing.h"

t_args	*last_arg(t_args *lst)
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
		node = last_arg(*lst);
		node->next = new;
	}
	else
		*lst = new;
}

// t_args	*word_add(t_token *token, int tab_sz)
// {
	
// }
t_args	*check_tokens(t_token *token, t_args *head)
{
	int tab_sz;
	
	tab_sz = cmd_length(token);
	printf("%d\n", tab_sz);
	exit(0);
	while (token && token->type == PIPE)
	{
		
	}
	if (token->type == PIPE)
		check_tokens(token, head);

}
t_args  *parcing(t_token *token)
{
	t_args  *head;

	head = NULL;
	if (!token)
		return (NULL);
	check_tokens(token, head);
	return (head);
}
