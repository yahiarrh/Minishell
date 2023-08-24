/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 02:36:50 by yrrhaibi          #+#    #+#             */
/*   Updated: 2022/10/29 12:37:13 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*sr;
	char		*ds;

	i = 0;
	ds = (char *)dst;
	sr = (char *)src;
	if (dst == src)
		return (dst);
	while (i < n)
	{
		ds[i] = sr[i];
		i++;
	}
	return (dst);
}
