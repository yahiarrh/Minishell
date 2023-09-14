/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 09:24:04 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/09/14 18:02:18 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>

int main(int ac, char **av, char **envp)
{
	t_env *env;

	(void)av;
	(void)ac;

	g_exit_status = 0;
	env = ft_getenv(envp);
	char *prompt = "minis : ";
	char *line;
	while (1)
	{
		line = readline(prompt);
		if (!line)
			exit(0);
		if(*line)
			add_history(line);
		if (!ft_strcmp("pwd", line))
			ft_pwd(&env);
		if (!ft_strcmp("env", line))
			ft_env(&env);
		if (!ft_strcmp("exit", ft_split(line, ' ')[0]))
			ft_exit(ft_split(line, ' '));
		if (!ft_strcmp(line, "echo"))
		{
			line = readline(prompt);
				ft_echo(ft_split(line, ' '));		
		}
		if(!ft_strcmp("cd", line))
		{
			line = readline(prompt);
			if (ft_strlen(line) == 0)
				ft_cd(&env, NULL);
			else
				ft_cd(&env, line);
		}
		if(!ft_strcmp("unset", ft_split(line, ' ')[0]))
			ft_unset(&env, ft_split(line, ' '));
		if(!ft_strcmp("export", ft_split(line, ' ')[0]))
				ft_export(&env, ft_split(line, ' '));
	}
} 