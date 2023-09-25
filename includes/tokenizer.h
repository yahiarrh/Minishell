/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 08:11:09 by msaidi            #+#    #+#             */
/*   Updated: 2023/09/23 16:21:06 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
#define TOKENIZER_H

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <readline/readline.h>
#define INDICATORS " \'\"|<>"
#define SYN "syntax error"

typedef struct s_token
{
	char			*word;
	int				type;
	struct s_token	*next;
	struct s_token	*down;
}t_token;

typedef struct s_flags
{
	int	len;
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
typedef struct s_redir
{
	char	*cmdline;
	int		type;
}t_redir;

typedef struct s_pipe
{
	char	*cmdline;
	int		type;
}t_pipe;

typedef struct s_args
{
	char	*cmdline;
	int		type;
	t_redir	*redir;
	t_pipe	*pipe;
	struct s_args *next;
}t_args;

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
t_token  *redirin_tok(void);
t_token  *redirout_tok(void);
t_token  *append_tok(void);
t_token  *heredoc_tok(void);
t_token	*double_quotes(char *arg, t_flags *flag);
t_token	*single_quotes(char *arg, t_flags *flag);
t_token	*ft_quotes(char *arg, t_flags *flag);
int		chr_q(char *str, t_flags *flag, char q);
t_args  parcing(t_token *token);
t_args	*check_syntax(t_token *token);

#endif
