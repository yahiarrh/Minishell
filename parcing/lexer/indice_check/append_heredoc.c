/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:10:59 by msaidi            #+#    #+#             */
/*   Updated: 2023/10/15 14:33:02 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

t_token	*append_tok(void)
{
	t_token	*token;

	token = get_ptr(sizeof(t_token), 1);
	token->type = APPEND;
	token->word = get_ptr(sizeof(char) * 3, 1);
	token->word[0] = '>';
	token->word[1] = '>';
	token->word[2] = '\0';
	token->next = NULL;
	token->down = NULL;
	return (token);
}

t_token	*heredoc_tok(void)
{
	t_token	*token;

	token = get_ptr(sizeof(t_token), 1);
	token->type = HEREDOC;
	token->word = get_ptr(sizeof(char) * 3, 1);
	token->word[0] = '<';
	token->word[1] = '<';
	token->word[2] = '\0';
	token->next = NULL;
	token->down = NULL;
	return (token);
}
