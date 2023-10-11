/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pars2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:02:48 by msaidi            #+#    #+#             */
/*   Updated: 2023/10/11 15:22:06 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
		new_arg->fd_out = open(expand(&env, token->next->word), O_CREAT | O_RDWR, 0644);
	else if (token->type == APPEND)
		new_arg->fd_out = open(expand(&env, token->next->word),
				O_CREAT | O_APPEND, 0644);
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
