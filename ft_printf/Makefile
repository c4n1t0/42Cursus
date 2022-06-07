NAME	= libftprintf.a

SOURCES	= ft_printf.c ft_printf_utils.c hexadecimales.c

OBJECTS	= $(SOURCES:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJECTS)
			ar rcs $(NAME) $(OBJECTS)

%.o: %.c
			$(CC) $(CFLAGS) -c $?

clean:
			rm -f $(OBJECTS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re