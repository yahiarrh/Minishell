/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 09:24:04 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/12 17:02:26 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>

// static t_gt	*last_ptr(t_gt *lst)
// {
// 	if (!lst)
// 		return (lst);
// 	while (lst->next)
// 		lst = lst->next;
// 	return (lst);
// }

// static void add_ptr(t_gt **head, t_gt *new)
// {
// 	t_gt	*tmp;

// 	if (!head || !new)
// 		return ;
// 	if (!*head)
// 	{
// 		*head = new;
// 		return ;
// 	}
// 	tmp = last_ptr(*head);
// 	tmp->next = new;
// }

// void	*get_ptr(size_t i, int flag)
// {
// 	void	*ptr;
// 	static t_gt	*head;
// 	t_gt	*tmp;

// 	tmp = NULL;
// 	if (flag == 1)
// 	{
// 		ptr = malloc(i);
// 		if (!ptr)
// 			return (NULL);
// 		tmp = malloc(sizeof(t_gt));
// 		tmp->ptr = ptr;
// 		add_ptr(&head, tmp);
// 		return (ptr);
// 	}
// 	else
// 	{
// 		while (head)
// 		{
// 			free(head->ptr);
// 			head = head->next;
// 		}
// 	}
// 	return (NULL);
// }

int main(int ac, char **av, char **envp)
{
	t_env *env;
	t_args *arg;
	t_token *token;

	(void)av;
	(void)ac;
	g_exit_status = 0;
	env = ft_getenv(envp);

	char *prompt = PROMPT;
	char *line;
	while (1)
	{
		line = readline(prompt);
		if(!line)
		{
			puts("HNA");
			break;
		}
		if(line)
			add_history(line);
		token = tokenizer(line);
		arg = parcing(token, env);
		
		if (!arg)
			continue;
		ft_exec(&env, arg);
		free(line);
	}
} 