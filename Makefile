NAME = minis

SRC	=	main.c builtins/cd.c builtins/echo.c builtins/env.c builtins/exit.c builtins/export.c builtins/ft_getval.c builtins/pwd.c builtins/unset.c\
builtins/utils/ft_err_msg.c  builtins/utils/lstadd_back.c builtins/utils/lstlast.c     builtins/utils/lstnew.c      builtins/utils/util.c\
		executor/commands/exec_comm.c executor/commands/exev.c executor/commands/filtre_comm.c executor/signals/signal.c expander/exp_utils.c expander/expand.c\
		parcing/parcing.c parcing/utils_pars.c parcing/utils_pars2.c parcing/lexer/tokenizer.c parcing/lexer/indice_check/append_heredoc.c\
		parcing/lexer/indice_check/wrd_pipe.c parcing/lexer/utils/ft_tokchr.c parcing/lexer/utils/token_back.c parcing/lexer/indice_check/quotes.c parcing/lexer/utils/ft_subtoken.c parcing/lexer/utils/last_token.c


 
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g

CC		= cc

RM 		= rm -rf

HEADERM = minishell.h

LDFLAGS="-L/Users/yrrhaibi/.brew/opt/readline/lib"

CPPFLAGS="-I/Users/yrrhaibi/.brew/opt/readline/include"

LIBFT = libft/libft.a

OBJS	= $(SRC:.c=.o)

%.o : %.c $(HEADERM)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

all	: $(NAME)

$(NAME) : $(OBJS)
	@make -C libft
	@cc $(OBJS) -o $(NAME) $(CPPFLAGS) $(LDFLAGS) $(LIBFT) -lreadline  $(CFLAGS)

clean :
	@make clean -C libft
	$(RM) $(OBJS)


fclean : clean
	@make fclean -C libft
	@$(RM) $(NAME)


re : fclean all

.PHONY : all clean fclean re