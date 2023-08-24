/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:00:57 by yrrhaibi          #+#    #+#             */
/*   Updated: 2022/10/26 16:12:59 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*ptr;

	if (!lst || !*lst || !del)
		return ;
	ptr = *lst;
	while (ptr)
	{
		del (ptr->content);
		free (ptr);
		ptr = ptr->next;
	}
	*lst = NULL;
}
