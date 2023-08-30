NAME = libft.a

SRC	=	ft_atoi.c ft_calloc.c ft_isalnum.c ft_isdigit.c ft_itoa.c\
		ft_memcmp.c ft_memmove.c ft_putchar_fd.c ft_putnbr_fd.c ft_split.c\
		ft_strdup.c ft_strjoin.c ft_strlcpy.c ft_strmapi.c ft_strnstr.c\
		ft_strtrim.c ft_tolower.c ft_bzero.c ft_isalpha.c ft_isascii.c\
		ft_isprint.c ft_memchr.c ft_memcpy.c ft_memset.c ft_putendl_fd.c\
		ft_putstr_fd.c ft_strchr.c ft_striteri.c ft_strlcat.c ft_strlen.c\
		ft_strncmp.c ft_strrchr.c ft_substr.c ft_toupper.c\
		ft_lstadd_front.c ft_lstdelone.c f_lstnew.c\
		ft_lstsize.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\

CFLAGS	= -Wall -Werror -Wextra 

CC		= cc

RM 		= rm -rf

AR		= ar -rc

LIBFTH = libft.h

OBJS	= $(SRC:.c=.o)

all	: $(NAME)

$(NAME) : $(OBJS)
	@$(AR) $@ $?

%.o :  %.c $(LIBFTH) 
	@$(CC) -c $(CFLAGS) $<

clean :
	$(RM) $(OBJS) $(OBJS_B)


fclean : clean 
	$(RM) $(NAME)


re : fclean all bonus

.PHONY : all clean fclean re
