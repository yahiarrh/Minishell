/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 00:31:32 by yrrhaibi          #+#    #+#             */
/*   Updated: 2022/10/30 18:23:57 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	ch;	
	char			*f;

	i = 0;
	f = (char *)b;
	ch = (unsigned char)c;
	while (len != 0)
	{
		f[i] = ch;
		i++;
		len--;
	}
	return (b);
}
