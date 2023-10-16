/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_comm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:21:18 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/15 14:21:15 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

bool	check_dir(char *path)
{
	struct stat	file;

	stat(path, &file);
	if ((*path == '/' || *path == '.')&& access(path, F_OK))
		return(ft_err_msg(NULL, path, ": No such file or directory\n", 0), true);
	if (S_ISDIR(file.st_mode))
		return(ft_err_msg(NULL, path, ": is a directory\n", 0), true);
	if (!access(path, F_OK) && access(path, X_OK))
		return(ft_err_msg(NULL, path, ": Permission denied\n", 0), true);
	return (false);
}

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
		env = env->next;
	}
	s[i] = NULL;
	return (s);
}

static char *find_path(char *comm, char **path)
{
	char	*tmp;
	char	*tmp1;

	if (comm && (*comm == '.' || *comm == '/'))
		return (comm);
	while (*path)
	{
		tmp1 = ft_strjoin(*path, "/");
		tmp = ft_strjoin(tmp1, comm);
		if (!access(tmp, X_OK))
			return (tmp);
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
	if (check_dir(comm[0]))
		exit(126);
	ft_err_msg(NULL, comm[0], ": command not found\n", 0);
		exit(127);
}