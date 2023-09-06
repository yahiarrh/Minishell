NAME = tokenizer

SRC	=	tokenizer.c ./utils/ft_strchr.c ./utils/ft_strlen.c ./utils/ft_substr.c ./utils/last_token.c ./utils/token_back.c \
		./utils/ft_strdup.c ./indice_check/quotes.c ./indice_check/wrd_pipe.c
 
CFLAGS	= -Wall -Wextra -Werror

CC		= cc

RM 		= rm -rf

HEADERM = tokenizer.h


OBJS	= $(SRC:.c=.o)

%.o : %.c  $(LIBFT_H)
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