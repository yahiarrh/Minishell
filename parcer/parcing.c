/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:54:40 by msaidi            #+#    #+#             */
/*   Updated: 2023/10/03 15:58:29 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parcing.h"

t_args	*last_arg(t_args *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	arg_back(t_args **lst, t_args *new)
{
	t_args	*node;


	if (!new || !lst)
		return ;
	if (*lst)
	{
		node = last_arg(*lst);
		node->next = new;
	}
	else
		*lst = new;
}
t_args	*redir_proc(t_token *token, t_env *env)
{
	t_args	*new;

	new = malloc(sizeof(t_args *));
	if (token->type == REDIN)
		new->fd_in = open(expand(&env, token->word), O_CREAT, 0644);
	else if (token->type == REDOUT)
		new->fd_out = open(expand(&env, token->word), O_CREAT, 0644);
	else if (token->type == APPEND)
		new->fd_out = open(expand(&env, token->word), O_CREAT | O_APPEND, 0644);
	else if (token->type == HEREDOC)
		puts("nothin. hh\n"); //dir heredoc..
	new->cmd = NULL;
	new->next = NULL;
	return (new);

}
t_args	*check_tokens(t_token *token, t_args *head, t_env *env)
{

	while (token && token->type == PIPE)
	{
		if (token->type > 4)
			arg_back(&head, redir_proc(token, env));
	}
	if (token->type == PIPE)
		check_tokens(token, head);
	return (head);
}
t_args  *parcing(t_token *token, t_env *env)
{
	t_args  *head;

	head = NULL;
	if (!token)
		return (NULL);
	check_tokens(token, head, env);
	return (head);
}
