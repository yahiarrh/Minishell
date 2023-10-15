/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrd_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:06:23 by msaidi            #+#    #+#             */
/*   Updated: 2023/10/15 14:33:41 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

t_token	*word_tok(char *arg, int len)
{
	t_token	*command;
	int		i;

	i = 0;
	command = get_ptr(sizeof(t_token), 1);
	command->word = ft_subtoken(arg, 0, len);
	command->type = WORD;
	command->next = NULL;
	command->down = NULL;
	return (command);
}

t_token	*pipe_tok(void)
{
	t_token	*token;

	token = get_ptr(sizeof(t_token), 1);
	token->type = PIPE;
	token->word = get_ptr(sizeof(char) * 2, 1);
	token->word[0] = '|';
	token->word[1] = '\0';
	token->next = NULL;
	token->down = NULL;
	return (token);
}

t_token	*redirin_tok(void)
{
	t_token	*token;

	token = get_ptr(sizeof(t_token), 1);
	token->type = REDIN;
	token->word = get_ptr(sizeof(char) * 2, 1);
	token->word[0] = '<';
	token->word[1] = '\0';
	token->next = NULL;
	token->down = NULL;
	return (token);
}

t_token	*redirout_tok(void)
{
	t_token	*token;

	token = get_ptr(sizeof(t_token), 1);
	token->type = REDOUT;
	token->word = get_ptr(sizeof(char) * 2, 1);
	token->word[0] = '>';
	token->word[1] = '\0';
	token->next = NULL;
	token->down = NULL;
	return (token);
}
