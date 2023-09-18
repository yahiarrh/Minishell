/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subtoken.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:50:48 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/09/18 12:07:08 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tokenizer.h"

char	*ft_subtoken(char const *s, unsigned int start, int len)
{
	int		i;
	char	*sub;
	int		st;

	if (!s)
		return (NULL);
	if (len == 0 || ft_strlen(s) <= start)
		return (ft_strdup(""));
	i = 0;
	st = ft_strlen(s + start);
	if (start < (unsigned int)len)
		sub = (char *)malloc(sizeof(char) * (st + 1));
	else
		sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	while (s[start] && i < len)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
