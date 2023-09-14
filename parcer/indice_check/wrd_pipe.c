/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrd_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:06:23 by msaidi            #+#    #+#             */
/*   Updated: 2023/09/14 17:21:36 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tokenizer.h"

t_token	*word_tok(char *arg, int len)
{
	t_token *command;
	int	i;

	i = 0;
	command = malloc(sizeof(t_token));
	command->word = ft_subtoken(arg, 0, len);
	command->type = WORD;
	command->next = NULL;
	command->down = NULL;
	return (command);
}

t_token  *pipe_tok(void)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
    token->type = PIPE;
	token->word = malloc(sizeof(char) * 2);
	token->word[0] = '|';
	token->word[1] = '\0';
	token->next = NULL;
	token->down = NULL;
    return (token);
}
