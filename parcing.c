/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:54:40 by msaidi            #+#    #+#             */
/*   Updated: 2023/10/07 16:17:47 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parcing.h"

int	ft_cmdsize(t_cmd *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	printf("count ==> %d\n", count);
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
t_cmd	*exp_last(t_cmd *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	sq_case(t_cmd **head, t_token *token)
{
	t_cmd	*tmp;
	char	*s;

	tmp = exp_last(*head);
	s = ft_strdup(tmp->cmd);
	free(tmp->cmd);
	tmp->cmd = ft_strjoin(s, ft_strdup(token->word));
	free(s);
}
void	dq_case(t_env **env, t_cmd **head, t_token *token)
{
	t_cmd	*tmp;
	char	*s;

	tmp = exp_last(*head);
	s = ft_strdup(tmp->cmd);
	free(tmp->cmd);
	tmp->cmd =  ft_strjoin(s, expand(env, token->word));
	free(s);
}
void	wrd_case(t_env **env, t_cmd **head, t_token *token)
{
	char	**s;
	t_cmd	*tmp;
	int		i;

	i = 0;
	s = ft_split(expand(env, token->word), ' ');
	if (!s)
		return ;
	while (s[i])
	{
		if (!i)
		{
			(*head)->cmd = *s;
			i++;
			continue ;
		}
		tmp = malloc(sizeof(t_cmd));
		tmp->next = NULL;
		tmp->cmd = s[i];
		cmd_back(head, tmp);
		i++;
	}
}
t_cmd	*filtre_exp(t_env **env, t_token *token)
{
	t_cmd	*head;

	head = malloc(sizeof(t_cmd));
	ft_memset(head, 0, sizeof(t_cmd));
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

bool	fill_redir(t_token *token, t_args *new_arg , t_env *env)
{
	t_cmd	*tmp;

	tmp = filtre_exp(&env, token->next);
	if (ft_cmdsize(tmp) > 1)
		return (printf("%s: ambiguous redirect\n", token->next->word), false);
	if (!tmp->cmd && token->next && token->next->type == PIPE)
		return (false);
	else if (token->type == REDIN)
		new_arg->fd_in = open(expand(&env, token->next->word), O_CREAT, 0644);
	else if (token->type == REDOUT)
			new_arg->fd_out = open(expand(&env, token->next->word), O_CREAT, 0644);
	else if (token->type == APPEND)
		new_arg->fd_out = open(expand(&env, token->next->word), O_CREAT | O_APPEND, 0644);
	else if (token->type == HEREDOC)
		new_arg->fd_in = heredoc(env, expand(&env, token->next->word));
	return (true);
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
			if (!((*token)->next) || !(fill_redir((*token), new_arg, env)))
				return (NULL);
			(*token) = (*token)->next;
		}
		else
			cmd_back(&new_arg->cmd, filtre_exp(&env, *token));
		(*token) = (*token)->next;
	}
	return (new_arg);
}

void	print_syn(t_token *token)
{
	char *err;

	err = "newline";
	if  (last_token(token)->type == PIPE || token->type == PIPE)
		err = "|";
	printf("syntax error near unexpected token `%s'\n",err);
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
