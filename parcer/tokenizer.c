/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 08:10:01 by msaidi            #+#    #+#             */
/*   Updated: 2023/09/03 15:30:38 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

int	spc_chk(char c)
{
	if (c && (c == ' ' || c == '\t'))
		return (1);
	return (0);
}

t_list	*indicator_check(char *arg)
{

}

int	ft_delim(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(INDICATORS, str[i++]))
			break ;
	}
	return (i);
}

t_list	*word_tok(char *arg)
{
	t_list *command;
	int	i;

	i = 0;
	command = malloc(sizeof (t_list *));
	command->type = WORD;
	command->word = ft_substr(arg, 0, ft_delim(arg));
	command->next ;
	return (command);
}

t_list	*tokenizer(char *arg)
{
	t_list	*head;
	int		i;
	bool	spc;

	i = -1;
	while (arg[++i])
	{
		if (ft_strchr(INDICATORS, arg[i]) || spc_chk(arg[i]))
		{
			if (arg[i] == ' ')
				spc = 1;
			token_back(&head, indicator_check(arg + i));
		}
		else
			token_back(&head, word_tok(arg + i));

		
	}
	return (head);
}

int main ()
{
	char *s = "";
}