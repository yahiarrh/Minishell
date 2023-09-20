/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:36:47 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/09/20 11:56:28 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_env	*ft_lstnew(char *content)
{
	t_env	*s;

	s = malloc(sizeof(t_env));
	if (!s)
		return (NULL);
	s->name = ft_strdup(content);
	s->value = NULL;
	s->next = NULL;
	return (s);
}
