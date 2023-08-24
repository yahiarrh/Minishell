/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:44:54 by yrrhaibi          #+#    #+#             */
/*   Updated: 2022/10/31 01:14:36 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	f;

	i = 0;
	j = ft_strlen(needle);
	if (j == 0)
		return ((char *)(haystack));
	if (len == 0 && needle[i])
		return (NULL);
	while (haystack[i] && i < len)
	{
		f = 0;
		while (haystack[i + f] == needle[f] && needle[f] && i + f < len)
			f++;
		if (f == j)
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
