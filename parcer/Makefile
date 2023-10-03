NAME = tokenizer

SRC	=	tokenizer.c ./utils/ft_tokchr.c ./utils/ft_strlen.c ./utils/ft_subtoken.c ./utils/last_token.c ./utils/token_back.c \
		./utils/ft_strdup.c ./indice_check/quotes.c ./indice_check/wrd_pipe.c ./indice_check/append_heredoc.c ../libft/ft_memset.c \
		parcing.c
 
CFLAGS	= -Wall -Wextra -Werror

CC		= cc

RM 		= rm -rf

HEADERM = ../includes/tokenizer.h ../includes/parcing.h


OBJS	= $(SRC:.c=.o)

%.o : %.c  $(HEADERM)
		$(CC) $(CFLAGS) -c -o $@ $<

all	: $(NAME)

$(NAME) : $(OBJS) 
	@cc $(OBJS) -o $(NAME) -lreadline  $(CFLAGS)

clean :
	$(RM) $(OBJS)


fclean : clean
	@$(RM) $(NAME)


re : fclean all

.PHONY : all clean fclean re