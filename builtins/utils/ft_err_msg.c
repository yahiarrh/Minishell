/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 08:48:12 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/09/07 14:12:06 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/blt_lib.h"

void	ft_err_msg(char *err, char *targ, char *erty)
{
	ft_putstr_fd(err, 2);
	ft_putstr_fd(targ, 2);
	ft_putstr_fd(erty, 2);
	return ;
}
