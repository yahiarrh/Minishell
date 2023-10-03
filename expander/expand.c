/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:23:25 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/03 15:50:00 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	checkarg(char arg)
{
	int	i;

	i = 1;
	if (!ft_isalpha(arg) && arg != '_')
		return (0);
	return (1);
}

static int	spc_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '$')
			break ;
		i++;
	}
	return (i);
}

static char	*extr_name(char *s)
{
	char	*nam;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (s[i] == '$')
	{
		nam = ft_substr("$", 0, 1);
		return (nam);
	}
	if (s[i] == '?')
	{
		nam = ft_substr("?", 0, 1);
		return (nam);
	}
	while (s[i] && s[i] != '$' && checkarg(s[0]))
	{
		if (!ft_isalnum(s[i]) && s[i] != '_')
			break ;
		i++;
	}
	nam = ft_substr(s, 0, i);
	return (nam);
}

static char	*ft_val(t_env **env, char *name, char *ret)
{
	if (ft_strcmp2(name, "?"))
		ret = ft_strjoin(ret, ft_itoa(g_exit_status));
	else if (!ft_getval(env, name))
		ret = ft_strjoin(ret, NULL);
	else
		ret = ft_strjoin(ret, ft_getval(env, name)->value);
	return (ret);
}

char	*expand(t_env **env, char *var)
{
	char	*name;
	char	*val;
	char	*ret;
	int		i;

	i = 0;
	ret = NULL;
	while (var[i])
	{
		val = ret;
		if (var[i] == '$')
		{
			name = extr_name(var + i + 1);
			ret = ft_val(env, name, ret);
			free(val);
			i += ft_strlen(name) + 1;
		}
		else
		{
			ret = ft_strjoin(ret, ft_substr(var, i, spc_len(var + i)));
			free(val);
			i += spc_len(var + i);
		}
	}
	return (ret);
}
t_cmd	*cmdlast(t_cmd *lst)
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
	ptr = cmdlast(*lst);
	ptr->next = new;
}
t_cmd *filtre_exp(t_env **env, t_token *token)
{
	t_cmd	*head;
	t_cmd	*tmp;

	if (token->type == DQ)
	{
		while (token)
		{
			tmp = malloc(sizeof(t_cmd));
			ft_memset(tmp, 0, sizeof(t_cmd));
			tmp->cmd = expand(env, token->word);
			cmd_back(&head, tmp);
			token = token->down;
			free(tmp);
		}
		return(head);
	}
}