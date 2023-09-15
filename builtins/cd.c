/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:25:41 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/09/15 11:49:49 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blt_lib.h"


// unset oldpwd & pwd + cd .. 
static void	ft_update_cd(t_env **env, char *name, char *nv)
{
	t_env	*tmp;

	if (!ft_getval(env, name))
	{
		tmp = ft_lstnew(name);
		ft_lstadd_back(env, tmp);
	}
	else
		tmp = ft_getval(env, name);
	tmp->value = nv;
}

static void	dash_case(t_env **env, char *op)
{
	if (!(ft_getval(env, "OLDPWD")))
	{
		ft_err_msg("bash: cd:", NULL, " OLDPWD not set\n");
		return ;
	}
	else if (!(ft_getval(env, "OLDPWD")->value))
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
		return ;
	}
	ft_update_cd(env, "PWD", getcwd(NULL, 0));
	ft_update_cd(env, "OLDPWD", op);
}

void	ft_cd(t_env **env, char *p)
{
	char	*op;

	op = getcwd(NULL, 0);
	if (!p || p[0] == '~')
		home_case(env, op);
	else if (p[0] == '-')
		dash_case(env, op);
	else
	{
		if (chdir(p))
			ft_err_msg("bash: cd: ", p, ": No such file or directory\n");
		if (ft_getval(env, "PWD"))
			ft_update_cd(env, "OLDPWD", op);
		ft_update_cd(env, "PWD", getcwd(NULL, 0));
	}
}
