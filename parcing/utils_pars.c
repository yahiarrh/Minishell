/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:02:48 by msaidi            #+#    #+#             */
/*   Updated: 2023/10/11 14:08:03 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_cmdsize(t_cmd *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

t_args	*last_arg(t_args *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
t_cmd	*cmd_last(t_cmd *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
void	cmd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*node;


	if (!new || !lst)
		return ;
	if (*lst)
	{
		node = cmd_last(*lst);
		node->next = new;
	}
	else
		*lst = new;
}
