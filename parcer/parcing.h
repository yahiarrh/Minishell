/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:02:23 by msaidi            #+#    #+#             */
/*   Updated: 2023/09/26 15:30:50 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PARCING_H
# define PARCING_H

# include "../includes/tokenizer.h"
# include <stdbool.h>

typedef struct s_redir
{
	char	*cmdline;
	bool	expand;
	struct s_redir *next;
}t_redir;

typedef struct s_cmd
{
	char	*cmdline;
	bool    expand;
	struct s_cmd *next;
}t_cmd;

typedef struct s_args
{
	t_redir	*redir;
	t_cmd	*cmd;
	struct s_args *next;
}t_args;

#endif