NAME	= ft_push_swap.a

SOURCES	=	push_swap_move_A.c push_swap_source_validator.c push_swap_utils_0.c push_swap.c \
			push_swap_move_B.c push_swap_app.c push_swap_move_tweece.c push_swap_100.c\
			push_swap_move_tweece_AB.c push_swap_utils_1.c push_swap_utils_2.c

OBJECTS	= $(SOURCES:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJECTS)
			@make -C libft/
			@cp libft/libft.a .
			@ar rcs $(NAME) $(OBJECTS)
			gcc -Wall -Wextra -Werror ft_push_swap.a libft.a -o push_swap
			make fclean

%.o: %.c
			$(CC) -c $(CFLAGS) $?

clean:
			@make clean -C libft/
			rm -f $(OBJECTS)

fclean:	
			@make fclean -C libft/
			@make clean
			rm -f $(NAME)
			rm -f libft.a

re:			fclean all
			rm -f push_swap

.PHONY:		all bonus clean fclean re