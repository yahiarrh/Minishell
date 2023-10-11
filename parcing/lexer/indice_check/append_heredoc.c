/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:10:59 by msaidi            #+#    #+#             */
/*   Updated: 2023/10/11 14:01:11 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

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