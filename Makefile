NAME = minis

SRC	=	main.c ./builtins/pwd.c ./builtins/lstutils/ft_lstadd_back.c ./builtins/lstutils/ft_lstlast.c ./builtins/ft_getval.c ./builtins/lstutils/ft_lstnew.c\
		./builtins/env.c ./builtins/echo.c ./builtins/cd.c ./builtins/unset.c ./builtins/export.c
 
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