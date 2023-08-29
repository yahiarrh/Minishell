NAME = minishell

SRC	=	main.c ./builtins/ft_getenv.c ./builtins/pwd.c ./builtins/ft_lstadd_back.c ./builtins/ft_lstlast.c ./builtins/ft_getval.c \
		./builtins/env.c ./builtins/echo.c ./builtins/cd.c
 
CFLAGS	= -Wall -Wextra -Werror

CC		= cc

RM 		= rm -rf

HEADERM =

LIBFT = libft/libft.a

OBJS	= $(SRC:.c=.o)

%.o : %.c 
	@$(CC) $(CFLAGS) -c -o $@ $<

all	: $(NAME)

$(NAME) : $(OBJS)
	@make -C libft
	@cc $(OBJS) -o $(NAME) $(LIBFT) -lreadline  $(CFLAGS)

clean :
	$(RM) $(OBJS)


fclean : clean
	@make fclean -C libft
	@$(RM) $(NAME)


re : fclean all

.PHONY : all clean fclean re