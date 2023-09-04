/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 08:11:09 by msaidi            #+#    #+#             */
/*   Updated: 2023/09/03 15:30:20 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
#define TOKENIZER_H

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <readline/readline.h>
#define INDICATORS "|\'\"<>"

typedef struct s_list
{
	char			*word;
	int				type;
	struct s_list	*next;
}t_list;

enum e_cmd
{
	WORD,
	PIPE,
	SQ,
	DQ,
	REDIN,
	REDOUT
};

t_list	*last_token(t_list *lst);
void	token_back(t_list **lst, t_list *new);
t_list	*tokenizer(char *arg);
int	ft_strchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, int len);
size_t	ft_strlen(const char *c);

#endif
