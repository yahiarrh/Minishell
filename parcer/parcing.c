/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:54:40 by msaidi            #+#    #+#             */
/*   Updated: 2023/10/04 16:22:33 by msaidi           ###   ########.fr       */
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
t_cmd	*cmd_last(t_cmd *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
void	cmd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*node;


	if (!new || !lst)
		return ;
	if (*lst)
	{
		node = cmd_last(*lst);
		node->next = new;
	}
	else
		*lst = new;
}

void	sq_case(t_cmd **head, t_token *token)
{
	t_cmd	*tmp;

	tmp = malloc(sizeof(t_cmd *));
	ft_memset(tmp, 0, sizeof(t_cmd));
	tmp->cmd = ft_strdup(token->word);
	cmd_back(head, tmp);
}
void	dq_case(t_env **env, t_cmd **head, t_token *token)
{
	t_cmd	*tmp;

	tmp = malloc(sizeof(t_cmd *));
	ft_memset(tmp, 0, sizeof(t_cmd));
	tmp->cmd = expand(env, token->word);
	cmd_back(head, tmp);
}
void	wrd_case(t_env **env, t_cmd **head, t_token *token)
{
	char	**s;
	t_cmd	*tmp;
	int i = 0;

	s = ft_split(expand(env, token->word), ' ');
	i = 0;
	while (s[i])
	{
		tmp = malloc(sizeof(t_cmd *));
		tmp->cmd = ft_strdup(s[i]);
		cmd_back(head, tmp);
		i++;
	}
}
t_cmd	*filtre_exp(t_env **env, t_token *token)
{
	t_cmd	*head;

	head = NULL;
	while (token)
	{
		if (token->type == SQ)
			sq_case(&head, token);
		else if (token->type == DQ)
			dq_case(env, &head, token);
		else if (token->type == WORD)
			wrd_case(env, &head, token);
		token = token->down;
	}
	return(head);
}

//===========================================================================================


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
void	fill_redir(t_token *token, t_args *new_arg , t_env *env)
{
	if (token->type == REDIN)
		new_arg->fd_in = open(expand(&env, token->word), O_CREAT, 0644);
	else if (token->type == REDOUT)
		new_arg->fd_out = open(expand(&env, token->word), O_CREAT, 0644);
	else if (token->type == APPEND)
		new_arg->fd_out = open(expand(&env, token->word), O_CREAT | O_APPEND, 0644);
	else if (token->type == HEREDOC)
		puts("nothin. hh\n"); //dir heredoc..
}
void	check_tokens(t_token *token, t_args **head, t_env *env)
{
	t_args	*new_arg;

	new_arg = malloc(sizeof(t_args *));
	if (!new_arg)
		return ;
	new_arg->fd_in = 0;
	new_arg->fd_out = 1;
	while (token && token->type != PIPE)
	{
		if (token->type > DQ)
		{
			if (!token->next)
			{
				printf("syntax error\n");
				exit(1);
			}
			fill_redir(token, new_arg, env);
			token = token->next;
		}
		else
		{
			cmd_back(&new_arg->cmd, filtre_exp(&env, token));
			token = token->next;
		}
		
	}
	new_arg->next = NULL;
	arg_back(head, new_arg);
	if (token)
		check_tokens(token, head, env);
}

t_args  *parcing(t_token *token, t_env *env)
{
	t_args  *head;

	head = NULL;
	if (!token)
		return (NULL);
	check_tokens(token, &head, env);
	return (head);
}
