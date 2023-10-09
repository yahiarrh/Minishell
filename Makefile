NAME = minis

SRC	=	main.c builtins/pwd.c builtins/utils/ft_lstadd_back.c builtins/utils/util.c builtins/utils/ft_lstlast.c builtins/ft_getval.c builtins/utils/ft_lstnew.c\
		builtins/env.c builtins/echo.c builtins/cd.c builtins/unset.c builtins/export.c builtins/exit.c builtins/utils/ft_err_msg.c\
		expander/expand.c expander/exp_utils.c executor/commands/exec_comm.c executor/commands/exev.c executor/commands/filtre_comm.c
 
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g

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
	@make clean -C libft
	$(RM) $(OBJS)


fclean : clean
	@make fclean -C libft
	@$(RM) $(NAME)


re : fclean all

.PHONY : all clean fclean re