/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:28:19 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/17 11:31:39 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_join(char const *s1, char const *s2)
{
	char	*ret;
	int		j;

	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ret = ft_strdup(s2), ret);
	ret = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (NULL);
	while (*s1)
		ret[j++] = *s1++;
	if (!s2)
		return (ret);
	while (*s2)
		ret[j++] = *s2++;
	ret[j] = '\0';
	return (ret);
}

char	*ft_dup(const char *s)
{
	char	*d;
	int		len;
	int		i;

	if (!s)
		return (NULL);
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

char	*ft_sub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*sub;

	if (!s)
		return (NULL);
	if (len == 0 || ft_strlen(s) <= start)
		return (ft_dup(""));
	i = 0;
	if (ft_strlen(s + start) < len)
		sub = (char *)malloc(sizeof(char) * (ft_strlen(s + start) + 1));
	if (ft_strlen(s + start) >= len)
		sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	while (s[start] && i < len)
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

int	ft_cmp2(const char *s1, const char *s2)
{
	unsigned char	*s11;
	unsigned char	*s22;
	size_t			i;

	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	i = 0;
	while (s11[i] && s11[i] == s22[0])
		i++;
	return (i);
}

int	ft_cmp(const char *s1, const char *s2)
{
	unsigned char	*s11;
	unsigned char	*s22;
	size_t			i;

	if (!s1 || !s2)
		return (-1);
	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	i = 0;
	while (s11[i] && s22[i] && s11[i] == s22[i])
		i++;
	return (s11[i] - s22[i]);
}
