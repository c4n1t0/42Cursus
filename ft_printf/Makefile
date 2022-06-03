NAME	= libftprintf.a

LIBFT	= libft

SOURCES	= ft_printf.c ft_printf_utils.c hexadecimales.c

OBJECTS	= $(SOURCES:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJECTS)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			$(AR) -r $@ $?

%.o: %.c
			$(CC) -c $(CFLAGS) $?

clean:
			rm -f $(OBJECTS)
			@make clean -C $(LIBFT)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re