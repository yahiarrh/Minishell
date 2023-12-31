/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pars2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:02:48 by msaidi            #+#    #+#             */
/*   Updated: 2023/10/19 10:48:38 by msaidi           ###   ########.fr       */
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

int	heredoc(t_env *env, char *delim, bool flag)
{
	char	*promt;
	char	*tmp;
	int		pipefd[2];

	pipe(pipefd);
	signal(SIGINT, herdoc_sig);
	while (isatty(STDIN_FILENO))
	{
		promt = readline("> ");
		if (!promt || !ft_strcmp(promt, delim))
		{
			free(promt);
			break ;
		}
		(flag) && (tmp = expand(&env, promt));
		(flag) && (write(pipefd[1], tmp, ft_strlen(tmp)));
		(flag) || (write(pipefd[1], promt, ft_strlen(promt)));
		write(pipefd[1], "\n", 1);
		free(promt);
	}
	if (sig_her(pipefd))
		return (-2);
	return (pipefd[0]);
}

bool	fill_redir(t_token *token, t_args *arg, t_env *env)
{
	t_cmd	*tmp;

	tmp = filtre_exp(&env, token->next);
	if (ft_cmdsize(tmp) != 1)
		return (printf("%s%s%s", P, token->next->word, F), arg->fd_in = -1, 1);
	if (arg->fd_in == -1)
		return (true);
	if (!tmp->cmd && token->next && token->next->type == PIPE)
		return (false);
	chk_redir(token, arg, env);
	if (arg->fd_in == -1 || arg->fd_in == -2)
	{
		if (arg->fd_in == -1)
			return (ft_err_msg(NULL, token->next->word, FILE_ERR, 1), 1);
		return (token->type = ERR_SIG, false);
	}
	return (true);
}

t_args	*check_tokens(t_token **token, t_env *env)
{
	t_args	*new_arg;

	new_arg = get_ptr(sizeof(t_args), 1);
	if (!new_arg)
		return (NULL);
	ft_memset(new_arg, 0, sizeof(t_args));
	new_arg->fd_in = 0;
	new_arg->fd_out = 1;
	while (*token && (*token)->type != PIPE)
	{
		if ((*token)->type > DQ)
		{
			if ((!(*token)->next || (*token)->next->type > DQ)
				|| !(fill_redir((*token), new_arg, env)))
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
	char	*err;

	err = "newline";
	if (last_token(token)->type == PIPE || token->type == PIPE)
		err = "|";
	else if (last_token(token)->type > DQ
		|| (token->type > DQ && token->type != ERR_SIG))
	{
		if (last_token(token)->type > DQ)
			err = ft_strdup(last_token(token)->word);
		else
			err = ft_strdup(token->next->word);
	}
	else if (token->type == ERR_SIG)
	{
		g_exit_status = 1;
		return ;
	}
	g_exit_status = 258;
	printf("syntax error near unexpected token `%s'\n", err);
}
