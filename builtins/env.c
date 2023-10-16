/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:16:33 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/15 11:15:56 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	if (!ft_getval(env, "PATH"))
		return(ft_err_msg(NULL, "env", ": No such file or directory\n", 127));
	while (tmp)
	{
		if (tmp->value)
			printf("%s=%s\n", tmp->name, tmp->value);
		tmp = tmp->next;
	}
}
