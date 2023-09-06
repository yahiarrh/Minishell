/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:14:59 by msaidi            #+#    #+#             */
/*   Updated: 2023/09/06 10:53:55 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tokenizer.h"

int	chr_q(char *str, char q)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == q)
			break ;
		i++;
	}
	if (str[i] == '\0')
		return (-1);
	return (i);
}


t_list  *double_quotes(char *arg, t_list *token)
{
	int	len;

	len = chr_q(arg + 1, '\"');
	if (len < 0)
	{
		printf("closi l quotes azaml\n");
		exit(1);
	}
	token->word = ft_substr(arg, 0, len);
	token->type = DQ;
	token->next = NULL;
	token->down = NULL;
	return (token);
}