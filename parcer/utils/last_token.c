/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:39:44 by msaidi            #+#    #+#             */
/*   Updated: 2023/09/18 12:07:21 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tokenizer.h"

t_token	*last_token(t_token *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
t_token	*last_down(t_token *lst)
{
	if (!lst)
		return (NULL);
	while (lst->down)
		lst = lst->down;
	return (lst);
}
