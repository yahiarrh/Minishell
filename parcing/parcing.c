/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:54:40 by msaidi            #+#    #+#             */
/*   Updated: 2023/10/15 18:07:57 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**join_cmds(t_cmd *command)
{
	char	**c;
	int		len;
	int		i;

	i = 0;
	len = ft_cmdsize(command);
	c = malloc(sizeof(char *) * (len + 1));
	while (i < len)
	{
		c[i] = ft_strdup(command->cmd);
		command = command->next;
		i++;
	}
	c[i] = NULL;
	return (c);
}

t_args  *parcing(t_token *token, t_env *env)
{
	t_args  *head;
	t_args  *tmp;
	
	head = NULL;
	if (!token)
		return (NULL);
	if (token->type == PIPE || last_token(token)->type == PIPE)
		return (print_syn(token), NULL);
	while (token)
	{
		tmp = check_tokens(&token, env);
		if (tmp)
			arg_back(&head, tmp);
		else
			break ;
		if (token)
			token = token->next;
	}
	if (token)
		return (print_syn(token), NULL); 
	return (head);
}
