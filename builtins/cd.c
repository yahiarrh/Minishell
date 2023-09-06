/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:25:41 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/09/06 13:46:22 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blt_lib.h"

static void	dash_case(t_env **env, char *op)
{
	if (!(ft_getval(env, "OLDPWD")->value))
	{
		ft_err_msg("bash: cd:", NULL, " OLDPWD not set\n");
		return ;
	}
	else
	{
		if (chdir(ft_getval(env, "OLDPWD")->value))
		{
			perror("chdir problem");
			return ;
		}
		ft_update(env, "PWD", ft_getval(env, "OLDPWD")->value);
		printf("%s\n", ft_getval(env, "OLDPWD")->value);
		ft_update(env, "OLDPWD", op);
	}
}

static void	home_case(t_env **env, char *op)
{
	if (chdir(ft_getval(env, "HOME")->value))
	{
		perror("chdir problem");
		return ;
	}
	ft_update(env, "PWD", ft_getval(env, "HOME")->value);
	ft_update(env, "OLDPWD", op);
}

static void	doublep_case(t_env **env, char *op)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (!ft_strcmp(op, "/"))
	{
		ft_update(env, "OLDPWD", "/");
		return ;
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
	}
	ft_update(env, "OLDPWD", op);
}

void	ft_cd(t_env **env, char *p)
{
	char	*op;

	op = ft_getval(env, "PWD")->value;
	if (!p)
		home_case(env, op);
	else if (p[0] == '-')
		dash_case(env, op);
	else
	{
		if (chdir(p))
			ft_err_msg("bash: cd: ", p, ": No such file or directory\n");
		if (p[0] == '/')
		{
			ft_update(env, "PWD", p);
			ft_update(env, "OLDPWD", op);
		}
		else if (!ft_strcmp(p, ".."))
			doublep_case(env, op);
		else
		{
			op = ft_strjoin(op, "/");
			ft_update(env, "PWD", ft_strjoin(op, p));
			ft_update(env, "OLDPWD", op);
		}
	}
}
