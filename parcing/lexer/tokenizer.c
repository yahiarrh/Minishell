/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 08:10:01 by msaidi            #+#    #+#             */
/*   Updated: 2023/10/17 11:34:22 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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
			return (2);
		}
		else
			token_back(token, redirin_tok(), 1);
	}
	else if (arg[0] == '>')
	{
		if (arg[1] == '>')
		{
			token_back(token, append_tok(), 1);
			return (2);
		}
		else
			token_back(token, redirout_tok(), 1);
	}
	else
		token_back(token, pipe_tok(), 1);
	return (1);
}

void	create_tokens(char *arg, t_token **head, t_flags *flag)
{
	int	i;

	i = 0;
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
			i += tok_indice(head, arg + i);
		}
		else if (arg[i] == '\'' || arg[i] == '\"')
			i = q_add(arg, head, flag, i);
		else
			i = wrd_add(head, flag, arg, i);
	}
}

t_token	*tokenizer(char *arg)
{
	t_token	*head;
	t_flags	*flag;

	flag = get_ptr(sizeof(t_flags), 1);
	flag->len = 0;
	flag->single_q = 0;
	flag->double_q = 0;
	flag->spc = 1;
	head = NULL;
	create_tokens(arg, &head, flag);
	if (flag->double_q || flag->single_q)
	{
		printf("syntax error quote not closed\n");
		return (NULL);
	}
	return (head);
}
