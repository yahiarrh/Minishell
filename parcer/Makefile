NAME = tokenizer

SRC	=	ft_strchr.c ft_strlen.c ft_substr.c last_token.c token_back.c tokenizer.c ft_strdup.c
 
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