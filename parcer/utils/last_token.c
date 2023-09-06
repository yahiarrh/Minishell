/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:39:44 by msaidi            #+#    #+#             */
/*   Updated: 2023/09/06 10:11:05 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tokenizer.h"

t_list	*last_token(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
