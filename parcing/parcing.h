#ifndef PARCING_C
#define PARCING_C

#include "../parcer/tokenizer.h"


typedef struct s_general
{
	t_command			*command;
	t_redir				*redir;
	struct s_general	*next;
}t_general;

typedef struct s_command
{
	char	**word;
	bool	expand;
}t_command;

typedef struct s_redir
{
	char			*redir;
	char			*file;
	struct s_redir	*next;
}t_redir;


#endif