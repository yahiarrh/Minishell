/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrd_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:06:23 by msaidi            #+#    #+#             */
/*   Updated: 2023/09/06 10:18:06 by msaidi           ###   ########.fr       */
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

t_list  *pipe_tok(t_list *cmdline)
{
    cmdline->type = PIPE;
	cmdline->word = malloc(sizeof(char) * 2);
	cmdline->word[0] = '|';
	cmdline->word[1] = '\0';
	cmdline->next = NULL;
    return (cmdline);
}
