/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 08:11:09 by msaidi            #+#    #+#             */
/*   Updated: 2023/10/13 14:50:52 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <readline/readline.h>
# include "../includes/blt_lib.h"

# define INDICATORS " \'\"|<>"

typedef struct s_token
{
	char			*word;
	int				type;
	struct s_token	*next;
	struct s_token	*down;
}t_token;

typedef struct s_flags
{
	int		len;
	bool	spc;
	bool	double_q;
	bool	single_q;
}t_flags;

enum e_cmd
{
	WORD = 1,
	PIPE,
	SQ,
	DQ,
	REDIN,
	REDOUT,
	APPEND,
	HEREDOC
};
t_token	*last_token(t_token *lst);
t_token	*last_down(t_token *lst);
void	token_back(t_token **lst, t_token *new, bool flag);
t_token	*tokenizer(char *arg);
int		ft_tokchr(const char *str, int c);
char	*ft_subtoken(char const *s, unsigned int start, int len);
size_t	ft_strlen(const char *c);
char	*ft_strdup(const char *s);
t_token	*word_tok(char *arg, int len);
t_token	*pipe_tok(void);
t_token	*redirin_tok(void);
t_token	*redirout_tok(void);
t_token	*append_tok(void);
t_token	*heredoc_tok(void);
t_token	*double_quotes(char *arg, t_flags *flag);
t_token	*single_quotes(char *arg, t_flags *flag);
t_token	*ft_quotes(char *arg, t_flags *flag);
int		chr_q(char *str, t_flags *flag, char q);
int		wrd_add(t_token *head, t_flags *flag, char *arg, int i);
int		q_add(char *arg, t_token *head, t_flags *flag, int i);
int		spc_chk(char c);
int		ft_delim(char *str);

#endif
