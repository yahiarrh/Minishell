/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:23:25 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/09/08 15:21:19 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	spc_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == ' ')
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
	while (s[i] && s[i] != '$' && ft_checkarg(&s[i]))
		i++;
	nam = ft_substr(s, 0, i);
	return (nam);
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
			i++;
			name = extr_name(var + i);
			ret = ft_strjoin(ret, ft_getval(env, name)->value);
			free(val);
			i += ft_strlen(name);
		}
		else
		{
			ret = ft_strjoin(ret, ft_substr(var, i, spc_len(var + i)));
			free(val);
			i = ft_strlen(ret);
		}
		i++;
	}
	return (ret);
}