/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:57:06 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/15 13:06:46 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	// if(!*s)
	// 	return (ft_strdup(""));
	i = 0;
	len = ft_strlen(s);
	d = (char *)malloc((len + 1) * sizeof(char));
	if (!d)
		return (NULL);
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
