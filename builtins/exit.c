/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 14:05:16 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/15 11:16:15 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	alph_arg(char **status)
{
	int		j;

	j = 0;
	while (status[1][j])
	{
		if (ft_isalpha(status[1][j]))
		{
			printf("exit\n");
			ft_err_msg("exit: ", status[1], 
				": numeric argument required\n", 0);
			exit (255);
		}
		j++;
	}
}

void	ft_exit(char	**status)
{
	char	s;
	int		i;

	i = 1;
	if (!status[1])
	{
		printf("exit\n");
		exit (0);
	}
	else
		alph_arg(status);
	while (status[i])
		i++;
	if (i > 2)
	{
		ft_err_msg("exit: ", NULL, "too many arguments\n", 1);
		return ;
	}
	else
	{
		s = (char)ft_atoi(status[1]);
		printf("exit\n");
		exit (s);
	}
}
