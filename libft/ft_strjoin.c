/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:06:31 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/09/10 12:49:22 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		j;

	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		ret = ft_strdup(s2);
		return (ret);
	}
	ret = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (*s1)
		ret[j++] = *s1++;
	if (!s2)
		return (ret);
	while (*s2)
		ret[j++] = *s2++;
	ret[j] = '\0';
	return (ret);
}
