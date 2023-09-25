/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:54:40 by msaidi            #+#    #+#             */
/*   Updated: 2023/09/23 16:30:52 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"

t_args	*check_syntax(t_token *token)
{
	t_args	*line;

	line = malloc(sizeof(t_args));
	if (token->type == PIPE)
}


t_args  parcing(t_token *token)
{
	t_args  *head;

	head = NULL;
	if (!token)
		return (NULL);
	head = check_syntax(token);

}