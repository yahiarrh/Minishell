/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:02:23 by msaidi            #+#    #+#             */
/*   Updated: 2023/10/03 15:05:22 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PARCING_H
# define PARCING_H

# include "tokenizer.h"
# include <stdbool.h>

typedef	struct s_cmd
{
	char	*cmd;
	struct s_cmd *next;
}t_cmd;

typedef struct s_args
{
	int				fd_in;
	int				fd_out;
	t_cmd			*cmd;
	struct s_args	*next;
}t_args;



t_args  *parcing(t_token *token);


#endif