/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 03:03:33 by yrrhaibi          #+#    #+#             */
/*   Updated: 2022/10/16 19:32:04 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*sr;
	char		*ds;

	sr = (char *)src;
	ds = (char *)dst;
	if (ds > sr)
	{
		while (len--)
			ds[len] = sr[len];
	}
	else
		ft_memcpy(ds, sr, len);
	return (ds);
}
