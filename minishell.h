/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:07:33 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/10/18 16:39:19 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <errno.h>
# include <unistd.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"
# include "includes/parcing.h"
# include "includes/tokenizer.h"
# include "includes/blt_lib.h"
# include "includes/expand.h"
# include "includes/exev.h"

int	g_exit_status;
# define PATH "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:\
/usr/local/munki:/Library/Apple/usr/bin"
# define ALLOC 1
# define FREE 0
# define F ": ambiguous redirect\n"
# define PROMPT "minishell: "
# define P "minishell: "

typedef struct s_gt
{
	void		*ptr;
	struct s_gt	*next;
}t_gt;

typedef struct s_std
{
	int	fd_in;
	int	fd_out;
}t_std;

#endif