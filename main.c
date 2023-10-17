/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 09:24:04 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/17 14:36:02 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	main_loop(t_token *token, t_env *env)
{
	char	*line;
	t_args	*arg;
	t_std	std;

	std.fd_in = dup(STDIN_FILENO);
	std.fd_out = dup(STDOUT_FILENO);
	arg = NULL;
	while (1)
	{
		(dup2(std.fd_out, STDOUT_FILENO)) && (dup2(std.fd_in, STDIN_FILENO));
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, inter_handler);
		line = readline("Minishell-1.0$ ");
		if (!line)
			return (printf("exit\n"), exit (0));
		if (line)
			add_history(line);
		token = tokenizer(line);
		arg = parcing(token, env);
		if (!arg)
			continue ;
		ft_exec(&env, arg);
		get_ptr(0, 0);
		free(line);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_env	*env;
	t_token	*token;

	rl_catch_signals = 0;
	(void)av;
	if (ac > 1)
		return (0);
	token = NULL;
	g_exit_status = 0;
	if (!envp || !*envp)
	{
		env = malloc(sizeof(t_env));
		ft_memset(env, 0, sizeof(t_env));
		renv(&env);
	}
	else
	{
		env = ft_getenv(envp);
		if (!ft_getval(&env, "SHLVL"))
			lstadd_back(&env, new("SHLVL", "1"));
		free(ft_getval(&env, "SHLVL")->value);
		ft_update(&env, "SHLVL", 
			ft_itoa(ft_atoi(ft_getval(&env, "SHLVL")->value) + 1));
	}
	main_loop(token, env);
}
