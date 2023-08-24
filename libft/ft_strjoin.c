/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:06:31 by yrrhaibi          #+#    #+#             */
/*   Updated: 2022/10/29 12:46:50 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;
	int		j;

	j = 0;
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = (char *)malloc(i * sizeof(char));
	if (!ret)
		return (0);
	while (*s1)
	{
		ret[j] = *s1;
		s1++;
		j++;
	}
	while (*s2)
	{
		ret[j] = *s2;
		s2++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}
