/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 07:58:59 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/09/03 14:37:57 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

char	*ft_strchr(const char *str, int c)
{
	char	ch;
	int		i;

	ch = (char)c;
	i = 0;
	if (c == 0)
		return ((char *)str + ft_strlen(str));
	while (str[i])
	{
		if (str[i] == ch)
			return ((char *)(str + i));
		i++;
	}
	return (0);
}
