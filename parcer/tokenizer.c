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
void	indicator_check(char *arg, t_list *command)
{
	

}

void	word_tok(char *arg, t_list *command)
{

}

t_list	tokenizer(char *arg)
{
	t_list	*command;
	int		i;

	i = -1;
	command = malloc(sizeof (*t_list));
	while (arg[++i])
	{
		while (arg[i] && arg[i] != ' ' && arg[i] != '\t')
			i++;
		if (ft_strchr("|\'\"<>", arg[i]) || spc_check(arg[i]))
			indicator_check(arg + i, command);
		else
			word_tok(arg + i, command);
		
	}
	return (command);
}
