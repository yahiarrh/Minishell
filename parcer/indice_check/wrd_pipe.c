/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrd_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:06:23 by msaidi            #+#    #+#             */
/*   Updated: 2023/09/10 12:18:10 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tokenizer.h"

t_list	*word_tok(char *arg, int len)
{
	t_list *command;
	int	i;

	i = 0;
	command = malloc(sizeof (t_list));
	command->type = WORD;
	command->word = ft_substr(arg, 0, len);
	command->next = NULL;
	return (command);
}

t_list  *pipe_tok(void)
{
	t_list	*token;

	token = malloc(sizeof(t_list));
    token->type = PIPE;
	token->word = malloc(sizeof(char) * 2);
	token->word[0] = '|';
	token->word[1] = '\0';
	token->next = NULL;
    return (token);
}
