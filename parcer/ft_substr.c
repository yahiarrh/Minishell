/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:50:48 by yrrhaibi          #+#    #+#             */
/*   Updated: 2022/10/30 18:31:25 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

char	*ft_substr(char const *s, unsigned int start, int len)
{
	int		i;
	char	*sub;
	int		start;

	if (!s)
		return (NULL);
	if (len == 0 || ft_strlen(s) <= start)
		return (ft_strdup(""));
	i = 0;
	start = ft_strlen(s + start);
	if (start < len)
		sub = (char *)malloc(sizeof(char) * (start + 1));
	else
		sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	while (s[start] && i < len)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
