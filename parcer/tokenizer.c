/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 08:10:01 by msaidi            #+#    #+#             */
/*   Updated: 2023/09/05 16:32:07 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

int	spc_chk(char c)
{
	if (c && (c == ' ' || c == '\t'))
		return (1);
	return (0);
}

t_list	*indicator_check(char *c)
{
	t_list	*cmdline;
	int	i;

	i = 0;
	cmdline = malloc(sizeof(t_list));
	if (c[i] == '|')
	cmdline->type = PIPE;
	cmdline->word = malloc(sizeof(char) * 2);
	cmdline->word[0] = '|';
	cmdline->word[1] = '\0';
	cmdline->next = NULL;
	return (cmdline);
}

int	ft_delim(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(INDICATORS, str[i]))
			break ;
		i++;
	}
	return (i);
}

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

t_list	*tokenizer(char *arg)
{
	t_list	*head;
	int		i;
	int		len;

	i = 0;
	head = NULL;
	while (arg[i])
	{
		if (ft_strchr(INDICATORS, arg[i]) || spc_chk(arg[i]))
		{
			token_back(&head, indicator_check(arg + i));
			i++;
		}
		else
		{
			len = ft_delim(arg + i);
			token_back(&head, word_tok(arg + i, len));
			i += len;
		}
	}
	return (head);
}

int main ()
{

	t_list	*f;

	f = tokenizer("ab|ls|ls|");
	while (f)
	{
		printf("word :: %s\n", f->word);
		printf("type :: %d\n", f->type);
		f = f->next;
	}
}
