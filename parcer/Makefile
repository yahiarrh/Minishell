NAME = tokenizer

SRC	=	tokenizer.c ./utils/ft_tokchr.c ./utils/ft_strlen.c ./utils/ft_subtoken.c ./utils/last_token.c ./utils/token_back.c \
		./utils/ft_strdup.c ./indice_check/quotes.c ./indice_check/wrd_pipe.c ./indice_check/append_heredoc.c ../libft/ft_memset.c \
		parcing.c expander.c ../builtins/pwd.c ../builtins/lstutils/ft_lstadd_back.c ../builtins/lstutils/ft_lstlast.c ../builtins/ft_getval.c ../builtins/lstutils/ft_lstnew.c\
		../builtins/env.c ../builtins/echo.c ../builtins/cd.c ../builtins/unset.c ../builtins/export.c ../builtins/exit.c
 
CFLAGS	= -Wall -Wextra -Werror

CC		= cc

RM 		= rm -rf

HEADERM = ../includes/tokenizer.h ../includes/parcing.h


LIBFT = ../libft/libft.a

OBJS	= $(SRC:.c=.o)

%.o : %.c  $(HEADERM)
		$(CC) $(CFLAGS) -c -o $@ $<

all	: $(NAME)

$(NAME) : $(OBJS)
	@make -C ../libft
	@cc $(OBJS) -o $(NAME) $(LIBFT) -lreadline  $(CFLAGS)

clean :
	$(RM) $(OBJS)


fclean : clean
	@make fclean -C ../libft
	@$(RM) $(NAME)


re : fclean all

.PHONY : all clean fclean re