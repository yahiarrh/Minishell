/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 09:24:04 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/08/30 14:50:51 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/blt_lib.h"
#include <readline/readline.h>

void	lak()
{
	system("leaks minis");
}

int main(int ac, char **av, char **envp)
{
	t_env *env;

	(void)av;
	(void)ac;

	env = ft_getenv(envp);
	char *prompt = "minis : ";
	char *line;
	atexit(lak);
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
		if (!ft_strcmp("exit", line))
			exit(0);
		if (!ft_strcmp("echo", line))
		{
			line = readline(prompt);
				ft_echo(ft_split(line, ' '));		
		}
		if(!ft_strcmp("cd", line))
		{
			line = readline(prompt);
			if (ft_strlen(line) == 0)
				ft_cd(&env, NULL);
			ft_cd(&env, line);
		}
		if(!ft_strcmp("unset", line))
		{
			line = readline(prompt);
			ft_unset(&env, line);
		}
		if(!ft_strcmp("export", line))
		{
			ft_export(&env, "d", "NULL");
		}
	}
}