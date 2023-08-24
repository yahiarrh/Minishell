/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:46:24 by yrrhaibi          #+#    #+#             */
/*   Updated: 2022/10/21 22:23:06 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	size_t			i;
	unsigned char	*f;

	ch = (unsigned char)c;
	f = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (f[i] == ch)
			return (f + i);
		i++;
	}
	return (NULL);
}
