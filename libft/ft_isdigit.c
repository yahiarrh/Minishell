/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:09:47 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/09/06 09:11:19 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_isdigit(long long c)
{
	if (c > (LLONG_MIN + 1) && c < (LLONG_MAX) - 1)
		return (1);
	else
		return (0);
}
