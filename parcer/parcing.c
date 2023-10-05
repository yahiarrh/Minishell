/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:54:40 by msaidi            #+#    #+#             */
/*   Updated: 2023/10/05 15:15:45 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parcing.h"

int	ft_cmdsize(t_cmd *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

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
	


	ft_strdup(token->word);
	
}
void	dq_case(t_env **env, t_cmd **head, t_token *token)
{
	

	expand(env, token->word);
	
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
		tmp = malloc(sizeof(t_cmd));
		ft_memset(tmp, 0, sizeof(t_cmd));
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
int	heredoc(t_env *env, char *delim)
{
	char *promt;
	char *buff;
	int pipefd[2];
	
	pipe(pipefd);
	while (1)
	{
		promt = readline("> ");
		if (!promt || !ft_strcmp(promt, delim))
		{
			free(promt);
			break ;
		}
		buff = expand(&env, promt);
		write(pipefd[1], buff, ft_strlen(buff));
		printf("%s\n", buff);
		write(pipefd[1], "\n", 1);
		free(buff);
		free(promt);
	}
	close(pipefd[1]);
	return (pipefd[0]);
}

void	fill_redir(t_token *token, t_args *new_arg , t_env *env)
{
	// if len cmds > 1 protect;
	t_cmd	*tmp;

	tmp = filtre_exp(&env, token->next);
	if (ft_cmdsize(tmp) > 1)
		printf("%s ambiguous redirect\n", token->next->word);
	while ()
	if (token->type == REDIN)
		new_arg->fd_in = open(expand(&env, token->next->word), O_CREAT, 0644);
	else if (token->type == REDOUT)
			new_arg->fd_out = open(expand(&env, token->next->word), O_CREAT, 0644);
	else if (token->type == APPEND)
		new_arg->fd_out = open(expand(&env, token->next->word), O_CREAT | O_APPEND, 0644);
	else if (token->type == HEREDOC)
		new_arg->fd_in = heredoc(env, expand(&env, token->next->word));
}
t_args	*check_tokens(t_token **token, t_env *env)
{
	t_args	*new_arg;

	new_arg = malloc(sizeof(t_args));
	if (!new_arg)
		return (NULL);
	ft_memset(new_arg, 0, sizeof(t_args));
	new_arg->fd_in = 0;
	new_arg->fd_out = 1;
	while (*token && (*token)->type != PIPE)
	{
		if ((*token)->type > DQ)
		{
			if (!(*token)->next)
			{
				printf("syntax error\n");
				return (NULL);
			}
			fill_redir((*token), new_arg, env);
			(*token) = (*token)->next;
		}
		else
			cmd_back(&new_arg->cmd, filtre_exp(&env, *token));
		(*token) = (*token)->next;
	}
	return (new_arg);
}
t_args  *parcing(t_token *token, t_env *env)
{
	t_args  *head;
	t_args  *tmp;

	head = NULL;
	if (!token)
		return (NULL);
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
		printf("syntax error near \'%s\'", token->word);
		return (NULL);
	}
	return (head);
}
