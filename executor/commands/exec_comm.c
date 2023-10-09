/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_comm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:21:18 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/07 14:23:03 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	lstsize(t_env *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

static char	**swtch_tp(t_env *env)
{
	char	**s;
	char	*tmp;
	int 	i;

	i = 0;
	s = malloc(sizeof(char *) * (lstsize(env) + 1));
	if (!s)
		return(NULL);
	while (env)
	{
		tmp = ft_strjoin(env->name, "=");
		s[i] = ft_strjoin(tmp, env->value);
		i++;
		free(tmp);
		env = env->next;
	}
	s[i] = NULL;
	return (s);
}

static char *find_path(char *comm, char **path)
{
	char	*tmp;

	while (*path)
	{
		tmp = ft_strjoin(*path, comm);
		if (!access(tmp, X_OK))
			return (tmp);
		free(tmp);
		path++;
	}
	return (NULL);
}

void    exec_comm(t_env **env, char **comm, char **path)
{
	char    *rpat;
	char    **cenv;

	rpat = find_path(comm[0], path);
	cenv = swtch_tp(*env);
	execve(rpat, comm, cenv);
}