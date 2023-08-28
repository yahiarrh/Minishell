/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 09:24:04 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/08/24 16:25:10 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/blt_lib.h"
#include <readline/readline.h>

int main(int ac, char **av, char **envp)
{
	t_env *env;

	(void)av;
	(void)ac;

	env = ft_getenv(envp);
	char *prompt = "minis : ";
	char *line;
	while (1)
	{
		line = readline(prompt);
		if (!line)
			exit(0);
		if (!ft_strcmp("pwd", line))
			ft_pwd(&env);
		if (!ft_strcmp("env", line))
			ft_env(&env);
		if (!ft_strcmp("exit", line))
			exit (EXIT_SUCCESS);
		if (!ft_strcmp("cd", line))
		{
			line = readline(prompt);
			ft_cd(&env, line);
		}
		
	}
}