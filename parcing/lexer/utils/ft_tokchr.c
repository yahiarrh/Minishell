/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 07:58:59 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/11 14:00:20 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	ft_tokchr(const char *str, int c)
{
	char	ch;
	int		i;

	ch = (char)c;
	i = 0;
	if (c == 0)
		return (2);
	while (str[i])
	{
		if (str[i] == ch)
			return (1);
		i++;
	}
	return (0);
}
