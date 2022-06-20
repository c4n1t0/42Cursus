NAME	= ft_push_swap.a

SOURCES	= push_swap_move.c push_swap_source_validator.c push_swap_utils.c push_swap.c

OBJECTS	= $(SOURCES:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	
			make libft/
			cp libft/libft.a ./
			make ft_printf/
			cp ft_printf/libftprintf.a ./			
			$(OBJECTS)
			ar rcs $(NAME) $(OBJECTS)

%.o: %.c
			$(CC) $(CFLAGS) -c $?

clean:
			rm -f $(OBJECTS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re