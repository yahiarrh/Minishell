/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:13:57 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/04 15:08:41 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blt_lib.h"

void	ft_pwd(t_env **env)
{
	t_env	*tmp;
	char	*pwd;

	tmp = ft_getval(env, "PWD");
	if (!tmp)
	{
		pwd = getcwd(NULL, 0);
		printf("%s\n",pwd);
		free(pwd);
		return ;
	}
	printf("%s\n",tmp->value);
}