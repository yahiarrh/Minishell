/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:10:59 by msaidi            #+#    #+#             */
/*   Updated: 2023/10/02 15:07:01 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tokenizer.h"

t_token  *append_tok(void)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
    token->type = APPEND;
	token->word = malloc(sizeof(char) * 3);
	token->word[0] = '>';
	token->word[1] = '>';
	token->word[2] = '\0';
	token->next = NULL;
	token->down = NULL;
    return (token);
}
t_token  *heredoc_tok(void)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
    token->type = HEREDOC;
	token->word = malloc(sizeof(char) * 3);
	token->word[0] = '<';
	token->word[1] = '<';
	token->word[2] = '\0';
	token->next = NULL;
	token->down = NULL;
    return (token);
}