/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 14:05:16 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/09/03 09:11:31 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blt_lib.h"

void	ft_exit(char	**status)
{
	int	i;
	int	j;

	i = 1;
	while (status[i])
	{
		j = 0;
		while (status[i][j])
		{
			if(ft_isalpha(status[i][j]))
			{
				printf("exit\n");
				ft_putstr_fd("bash: exit: ", 2);
				ft_putstr_fd(status[i], 2);
				ft_putstr_fd(" :numeric argument required\n", 2);
				exit (0);
			}
			j++;
		}
		if(!ft_isdigit(ft_atoi(status[i])))
		{
			printf("exit\n");
			ft_putstr_fd("bash: exit: ", 2);
			ft_putstr_fd(status[i], 2);
			ft_putstr_fd(" :numeric argument required\n", 2);
			exit (0);
		}
		i++;
	}
	if (i > 2)
	{
		ft_putstr_fd("bash: exit:", 2);
		ft_putstr_fd(" :too many arguments\n", 2);
		return;
	}
	else
	{
		printf("exit\n");
		exit (0);
	}
}