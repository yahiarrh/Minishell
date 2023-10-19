/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:21:33 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/19 11:39:45 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	count(long nbr)
{
	int	srt;

	srt = 0;
	if (nbr == 0)
		srt++;
	if (nbr < 0)
	{
		nbr *= -1;
		srt++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		srt++;
	}
	return (srt);
}

static char	*ret_nbr(char *str, long nbr, unsigned int size)
{
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	str[size] = '\0';
	size--;
	while (nbr > 0)
	{
		str[size--] = 48 + (nbr % 10);
		nbr /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	unsigned long	f;
	char			*c;
	int				i;

	i = 0;
	f = count(n);
	c = (char *)ft_get_ptr(sizeof(char) * (f + 1));
	if (!c)
		return (NULL);
	if (n == 0)
		c[i] = 48;
	c = ret_nbr(c, n, f);
	return (c);
}
