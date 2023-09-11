/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:14:59 by msaidi            #+#    #+#             */
/*   Updated: 2023/09/10 13:35:53 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tokenizer.h"

int	chr_q(char *str, char q)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == q)
			break ;
		count++;
		i++;
	}
	return (count);
}


t_list  *double_quotes(char *arg, int len)
{
	t_list	*token;

	token = malloc(sizeof(t_list));
	token->word = ft_substr(arg, 0, len);
	token->type = DQ;
	token->next = NULL;
	token->down = NULL;
	return (token);
}

t_list  *single_quotes(char *arg, int len)
{
	t_list	*token;

	token = malloc(sizeof(t_list));
	token->word = ft_substr(arg, 0, len);
	token->type = SQ;
	token->next = NULL;
	token->down = NULL;
	return (token);
}

t_list	*ft_quotes(char *arg, int len)
{
	t_list	*token;

	token = NULL;
	if (arg[0] == '\"')
		token = double_quotes(arg + 1, len);
	else if (arg[0] == '\'')
		token =single_quotes(arg + 1, len);
	return (token);
}
