/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 08:10:01 by msaidi            #+#    #+#             */
/*   Updated: 2023/09/10 14:51:30 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

int	spc_chk(char c)
{
	if (c && (c == ' ' || c == '\t'))
		return (1);
	return (0);
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
	t_flags	*j;
	int		i;


	i = 0;
	j = malloc(sizeof(t_flags));
	j->spc = 0;
	j->len = 0;
	head = NULL;
	while (arg[i])
	{
		while (spc_chk(arg[i]))
		{
			j->spc = 1;
			i++;
		}
		if (arg[i] == '|')
		{
			token_back(&head, pipe_tok());
			i++;
		}
		else if (arg[i] == '\'' || arg[i] == '\"')
		{
			j->len = chr_q(arg + (i + 1), arg[i]);
			token_back(&head, ft_quotes(arg + i, j->len));
			i += j->len + 2;
		}
		else if () // redirin and redirout
		{
			
		}
		else
		{
			j->len = ft_delim(arg + i);
			token_back(&head, word_tok(arg + i, j->len));
			i += j->len;
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
