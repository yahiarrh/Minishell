/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_back.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:03:48 by msaidi            #+#    #+#             */
/*   Updated: 2023/09/18 12:07:41 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tokenizer.h"

void	token_back(t_token **lst, t_token *new, bool flag)
{
	t_token	*node;


	if (!new || !lst)
		return ;
	if (*lst)
	{
		node = last_token(*lst);
		if (flag)
			node->next = new;
		else
		{
			if (!node->down)
				node->down = new;
			else
				(last_down(node))->down = new; 
		}
	}
	else
		*lst = new;
}
