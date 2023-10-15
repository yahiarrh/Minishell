/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:25:41 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/15 11:15:38 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_update_cd(t_env **env, char *name, char *nv)
{
	t_env	*tmp;

	if (!ft_getval(env, name))
	{
		tmp = lstnew(name);
		lstadd_back(env, tmp);
	}
	else
	{
		tmp = ft_getval(env, name);
	}
	tmp->value = ft_dup(nv);
}

static void	dash_case(t_env **env, char *op)
{
	if (!(ft_getval(env, "OLDPWD")))
	{
		ft_err_msg("cd:", NULL, " OLDPWD not set\n", 1);
		return ;
	}
	else if (!(ft_getval(env, "OLDPWD")->value))
	{
		ft_err_msg("cd:", NULL, " OLDPWD not set\n", 1);
		return ;
	}
	else
	{
		if (chdir(ft_getval(env, "OLDPWD")->value))
		{
			perror("chdir problem");
			return ;
		}
		ft_update_cd(env, "PWD", ft_getval(env, "OLDPWD")->value);
		printf("%s\n", ft_getval(env, "OLDPWD")->value);
		ft_update_cd(env, "OLDPWD", op);
	}
}

static void	home_case(t_env **env, char *op)
{
	if (chdir(ft_getval(env, "HOME")->value))
	{
		perror("chdir problem");
		g_exit_status = 1;
		return ;
	}
	ft_update_cd(env, "PWD", getcwd(NULL, 0));
	ft_update_cd(env, "OLDPWD", op);
}

void	ft_cd(t_env **env, char *p)
{
	char	*op;
	char	*o;

	op = getcwd(NULL, 0);
	o = NULL;
	if (!p || p[0] == '~')
		home_case(env, op);
	else if (p[0] == '-')
		dash_case(env, op);
	else
	{
		if (chdir(p))
		{
			ft_err_msg("cd: ", p, ": No such file or directory\n", 1);
			return ;
		}
		o = getcwd(NULL, 0);
		ft_update_cd(env, "PWD", o);
		ft_update_cd(env, "OLDPWD", op);
	}
	free(op);
	if (o)
		free(o);
}
