/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:07:33 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/09/26 13:07:40 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "includes/blt_lib.h"
# include "includes/expand.h"
# include "includes/exev.h"
# include "parcing/parcing.h"

int	g_exit_status;
# define PATH "/usr/local/bin:/usr/bin:/bin:/usr/sbin\
				:/sbin:/usr/local/munki:/Library/Apple/usr/bin"

typedef struct s_gt
{
	void		*ptr;
	struct s_gt *next;
}t_gt;

void	*get_ptr(size_t i, int flag);

#endif