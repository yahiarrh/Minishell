/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:25:41 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/09/01 09:11:33 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blt_lib.h"

void	ft_cd(t_env **env, char *p)
{
	char	*tmp;
	char	*op;
	int		i;

	i = 0;
	tmp = NULL;
	op = ft_getval(env, "PWD")->value;
	if (!p)
	{
		if(chdir(ft_getval(env, "HOME")->value))
		{
			perror("chdir problem");
			return;
		}
		ft_update(env, "PWD", ft_getval(env, "HOME")->value);
		ft_update(env, "OLDPWD", op);
		return;
	}
	if(p[0] == '-')
	{
		if (!(ft_getval(env, "OLDPWD")->value))
		{
			perror("OLDPWD not set");
			return;
		}
		else
		{
			if(chdir(ft_getval(env, "OLDPWD")->value))
			{
				perror("chdir problem");
				return;
			}
			ft_update(env, "PWD", ft_getval(env, "OLDPWD")->value);
			printf("%s\n",ft_getval(env, "OLDPWD")->value);
			ft_update(env, "OLDPWD", op);
			return;
		}
	}
	else
	{
		if (chdir(p))
		{
			perror("");
			return;
		}
		if (p[0] == '/')
		{
			ft_update(env, "PWD", p);
			ft_update(env, "OLDPWD", op);
			return;
		}
		else if (!ft_strcmp(p, ".."))
		{
			if (!ft_strcmp(op, "/"))
			{
				ft_update(env, "OLDPWD", "/");
				return;
			}
			i = ft_strlen(op);
			while (i && op[i] != '/')
				i--;
			if (!ft_strcmp(op, "/Users"))
				ft_update(env, "PWD", "/");
			else
			{
				tmp = malloc(i + 1);
				ft_strlcpy(tmp, op, i + 1);
				ft_update(env, "PWD", tmp);
				free(tmp);
			}
			ft_update(env, "OLDPWD", op);
			return;
		}
		else
		{
			op = ft_strjoin(op, "/");
			ft_update(env, "PWD", ft_strjoin(op, p));
			ft_update(env, "OLDPWD", op);
		}
	}
}