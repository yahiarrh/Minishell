/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:18:31 by yrrhaibi          #+#    #+#             */
/*   Updated: 2022/10/31 01:16:18 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	char			*ret;
	int				i;

	if (!s1)
		return (NULL);
	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i++]))
		start++;
	while (start < end && ft_strchr(set, s1[end - 1]))
		end--;
	ret = (char *)malloc((end - start + 1) * sizeof(char));
	if (!ret)
		return (0);
	ft_strlcpy(ret, &s1[start], end - start + 1);
	return (ret);
}
