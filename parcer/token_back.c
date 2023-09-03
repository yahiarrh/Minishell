/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_back.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:03:48 by msaidi            #+#    #+#             */
/*   Updated: 2023/09/03 10:15:47 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

void	token_back(t_list **lst, t_list *new)
{
	t_list	*node;

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
