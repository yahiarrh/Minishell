/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:57:06 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/09/06 10:10:56 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tokenizer.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	int		len;
	int		i;

	i = -1;
	len = ft_strlen(s);
	d = (char *)malloc((len + 1) * sizeof(char));
	if (!d)
		return (NULL);
	while (s[++i])
		d[i] = s[i];
	d[i] = '\0';
	return (d);
}
