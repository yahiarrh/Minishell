/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:54:40 by msaidi            #+#    #+#             */
/*   Updated: 2023/10/19 10:48:50 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	chk_redir(t_token *token, t_args *arg, t_env *env)
{
	if (token->type == REDIN)
		arg->fd_in = open(expand(&env, token->next->word), O_RDONLY, 0644);
	else if (token->type == REDOUT)
		arg->fd_out = open(expand(&env, token->next->word),
				O_CREAT | O_TRUNC | O_RDWR, 0644);
	else if (token->type == APPEND)
		arg->fd_out = open(expand(&env, token->next->word),
				O_CREAT | O_APPEND | O_RDWR, 0644);
	else if (token->type == HEREDOC)
		arg->fd_in = heredoc(env, join_downs(token->next),
				(token->next->type == WORD));
}

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
		return (print_syn(token), get_ptr(0, 0), NULL);
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
