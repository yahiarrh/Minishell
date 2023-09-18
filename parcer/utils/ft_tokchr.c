/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 07:58:59 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/09/18 12:06:34 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tokenizer.h"

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
