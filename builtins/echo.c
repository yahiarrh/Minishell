/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:04:30 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/09/06 14:03:07 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blt_lib.h"

static int	option(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	if (s[i] == 'n')
		i += ft_strcmp2(s + i, "n");
	if (s[i])
		return (0);
	return (i);
}

static void	pr_loop(char *s)
{
	int	oli;

	oli = 0;
	while (s[oli])
	{
		printf("%c", s[oli]);
		oli++;
	}
}

void	ft_echo(char **s)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (!s[0])
	{
		printf("\n");
		return ;
	}
	while (s[i][0] == '-' && s[i][1] == 'n')
	{
		if (!option(s[i]))
			break ;
		flag = 1;
		i++;
	}
	while (s[i])
	{
		pr_loop(s[i]);
		if (s[++i])
			printf(" ");
	}
	if (!flag)
		printf("\n");
}
