/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:37:53 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/15 14:31:06 by msaidi           ###   ########.fr       */
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
	tmp->cmd = ft_strjoin(s, expand(env, token->word));
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
		tmp = get_ptr(sizeof(t_cmd), 1);
		tmp->next = NULL;
		tmp->cmd = s[i];
		cmd_back(head, tmp);
		i++;
	}
}

t_cmd	*filtre_exp(t_env **env, t_token *token)
{
	t_cmd	*head;

	head = get_ptr(sizeof(t_cmd), 1);
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
	return (head);
}
