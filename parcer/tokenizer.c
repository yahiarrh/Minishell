/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 08:10:01 by msaidi            #+#    #+#             */
/*   Updated: 2023/09/06 13:43:26 by msaidi           ###   ########.fr       */
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

	cmdline = malloc(sizeof(t_list));
	if (c[0] == '|')
		pipe_tok(cmdline);
	else if (c[0] == '\"')
		double_quotes(c, cmdline);
	// else if (c[i] == '\"')
	// 	single_quote();
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
	char *prompt = "TOKE$> ";
	char *line;
	t_list	*f;

	while (1)
	{
		line = readline(prompt);
		f = tokenizer(line);
	
		while (f)
		{
			printf("word :: %s\n", f->word);
			printf("type :: %d\n", f->type);
			printf("---------------\n");
			f = f->next;
		}

	}

}
