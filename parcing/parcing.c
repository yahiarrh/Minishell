/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:54:40 by msaidi            #+#    #+#             */
/*   Updated: 2023/10/17 15:18:27 by msaidi           ###   ########.fr       */
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
	c = get_ptr(sizeof(char *) * (len + 1), 1);
	while (i < len)
	{
		c[i] = ft_strdup(command->cmd);
		command = command->next;
		i++;
	}
	c[i] = NULL;
	return (c);
}

t_args	*parcing(t_token *token, t_env *env)
{
	t_args	*head;
	t_args	*tmp;

	head = NULL;
	if (!token)
		return (get_ptr(0, 0), NULL);
	if (token->type == PIPE || last_token(token)->type == PIPE)
	{
		print_syn(token);
		get_ptr(0, 0);
		return (NULL);
	}
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
	{
		print_syn(token);
		return (get_ptr(0, 0), NULL);
	}
	return (head);
}
