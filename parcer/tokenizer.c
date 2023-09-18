/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 08:10:01 by msaidi            #+#    #+#             */
/*   Updated: 2023/09/18 12:05:27 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"

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
		if (ft_tokchr(INDICATORS, str[i]))
			break ;
		i++;
	}
	return (i);
}
int	tok_indice(t_token **token, char	*arg)
{
	if (arg[0] == '<')
	{
		if (arg[1] == '<')
		{
			token_back(token, heredoc_tok(), 1);
			return(2);
		}
		else
			token_back(token, redirin_tok(), 1);
	}
	else if (arg[0] == '>')
	{
		if (arg[1] == '>')
		{
			token_back(token, append_tok(), 1);
			return(2);
		}
		else
			token_back(token, redirout_tok(), 1);
	}
	else
		token_back(token, pipe_tok(), 1);
	return(1);
}

t_token	*tokenizer(char *arg)
{
	t_token	*head;
	t_flags	*flag;
	int		i;

	i = 0;
	flag = malloc(sizeof(t_flags));
	flag->len = 0;
	flag->single_q = 0;
	flag->double_q = 0;
	flag->spc = 1;
	head = NULL;
	while (arg[i])
	{
		if (spc_chk(arg[i]))
		{
			flag->spc = 1;
			i++;
		}
		else if (ft_tokchr("|<>", arg[i]))
		{
			flag->spc = 1;
			i += tok_indice(&head, arg + i);
		}
		else if (arg[i] == '\'' || arg[i] == '\"')
		{
			flag->len = chr_q(arg + i +1, flag, arg[i]);
			if(flag->len || (!flag->len && (flag->spc && spc_chk(arg[i + 2])))) 
				token_back(&head, ft_quotes(arg + i, flag), flag->spc);
			i += flag->len + 2;
			flag->spc = 0;
		}
		else
		{
			flag->len = ft_delim(arg + i);
			token_back(&head, word_tok(arg + i, flag->len), flag->spc);
			flag->spc = 0;
			i += flag->len;
		}
	}
	if (flag->double_q || flag->single_q)
		printf("quote not closed\n");
	return (head);
}

int main ()
{
	char *prompt = "TOKE$> ";
	char *line;
	t_token	*f;

	while (1)
	{
		line = readline(prompt);
		f = tokenizer(line);
	
		while (f)
		{
			printf("word :: %s\n", f->word);
			printf("type :: %d\n", f->type);
			if (f->down)
			{
				printf("down->word :: %s\n", f->down->word);
				printf("down->type :: %d\n", f->down->type);
			}
			printf("---------------\n");
			f = f->next;
		}

	}

}
