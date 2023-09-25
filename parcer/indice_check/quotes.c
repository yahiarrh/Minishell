/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:14:59 by msaidi            #+#    #+#             */
/*   Updated: 2023/09/14 18:15:08 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tokenizer.h"

int	chr_q(char *str, t_flags *flag, char q)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	(q == '\"') && (flag->double_q = !flag->double_q);
	(q == '\'') && (flag->single_q = !flag->single_q);
	while (str[i])
	{
		if (str[i] == q)
			break ;
		count++;
		i++;
	}
	(str[i] == '\"') && (flag->double_q = !flag->double_q);
	(str[i] == '\'') && (flag->single_q = !flag->single_q);
	return (count);
}


t_token  *double_quotes(char *arg, t_flags *flag)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return(NULL);
	token->word = ft_subtoken(arg, 0, flag->len);
	token->type = DQ;
	token->next = NULL;
	token->down = NULL;
	return (token);
}

t_token  *single_quotes(char *arg, t_flags *flag)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->word = ft_subtoken(arg, 0, flag->len);
	token->type = SQ;
	token->next = NULL;
	token->down = NULL;
	return (token);
}

t_token	*ft_quotes(char *arg, t_flags *flag)
{
	t_token	*token;

	token = NULL;
	if (arg[0] == '\"')
		token = double_quotes(arg + 1, flag);
	else if (arg[0] == '\'')
		token =single_quotes(arg + 1, flag);
	return (token);
}
