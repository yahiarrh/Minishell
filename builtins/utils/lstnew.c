/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:36:47 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/15 14:29:26 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_env	*lstnew(char *content)
{
	t_env	*s;

	s = get_ptr(sizeof(t_env), 1);
	if (!s)
		return (NULL);
	s->name = ft_strdup(content);
	s->value = NULL;
	s->next = NULL;
	return (s);
}
