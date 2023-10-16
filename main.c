/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 09:24:04 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/16 15:25:52 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>

t_gt	*last_ptr(t_gt *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_ptr(t_gt **head, t_gt *new)
{
	t_gt	*tmp;

	if (!head || !new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	tmp = last_ptr(*head);
	tmp->next = new;
}

void	*get_ptr(size_t i, int flag)
{
	void		*ptr;
	static t_gt	*head;
	t_gt		*tmp;

	tmp = NULL;
	if (flag == 1)
	{
		ptr = malloc(i);
		if (!ptr)
			return (NULL);
		tmp = malloc(sizeof(t_gt));
		tmp->ptr = ptr;
		tmp->next = NULL;
		add_ptr(&head, tmp);
		return (ptr);
	}
	else
	{
		while (head)
		{
			free(head->ptr);
			head = head->next;
		}
	}
	return (NULL);
}

void	main_loop(t_token *token, t_env *env)
{
	char	*prompt;
	char	*line;
	t_args	*arg;

	prompt = "Minishell$ ";
	arg = NULL;
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, inter_handler);
		line = readline(prompt);
		if (!line)
			return (printf("exit\n"), exit (0));
		if (line)
			add_history(line);
		token = tokenizer(line);
		arg = parcing(token, env);
		if (!arg)
			continue ;
		ft_exec(&env, arg);
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
		ft_update(&env, "SHLVL", 
			ft_itoa(ft_atoi(ft_getval(&env, "SHLVL")->value) + 1));
	}
	main_loop(token, env);
}
