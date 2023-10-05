/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:37:53 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/05 16:12:54 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd	*exp_last(t_cmd *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

static t_cmd	*cmd_last(t_cmd *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

static void	cmd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*ptr;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ptr = cmd_last(*lst);
	ptr->next = new;
}
static void	sq_case(t_cmd **head, t_token *token)
{
	t_cmd	*tmp;
	char	*s;

	tmp = exp_last(*head);
	s = tmp->cmd;
	free(tmp->cmd);
	tmp->cmd = ft_strjoin(s, ft_strdup(token->word));
	free(s);
}
static void	dq_case(t_env **env, t_cmd **head, t_token *token)
{
	t_cmd	*tmp;
	char	*s;

	tmp = exp_last(*head);
	s = tmp->cmd;
	free(tmp->cmd);
	tmp->cmd =  ft_strjoin(s, expand(env, token->word));
	free(s);
}
static void	wrd_case(t_env **env, t_cmd **head, t_token *token)
{
	char	**s;
	t_cmd	*tmp;

	s = ft_split(expand(env, token->word), ' ');
	while (*s)
	{
		tmp = get_ptr(sizeof(t_cmd), ALLOC);
		ft_memset(tmp, 0, sizeof(t_cmd));
		tmp->cmd = *s;
		cmd_back(head, tmp);
		s++;
	}
}
t_cmd	*filtre_exp(t_env **env, t_token *token)
{
	t_cmd	*head;

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