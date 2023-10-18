/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:36:47 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/18 11:31:41 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_env	*lstnew(char *content)
{
	t_env	*s;

	s = malloc(sizeof(t_env));
	if (!s)
		return (NULL);
	s->name = ft_dup(content);
	s->value = NULL;
	s->next = NULL;
	return (s);
}
