# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/26 01:08:42 by jaromero          #+#    #+#              #
#    Updated: 2022/07/27 14:14:41 by jaromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= srcs/ft_push_swap.a

SOURCES	=	srcs/push_swap_move_A.c srcs/push_swap_source_validator.c srcs/push_swap_utils_0.c srcs/push_swap.c \
			srcs/push_swap_move_B.c srcs/push_swap_app.c srcs/push_swap_move_tweece.c srcs/push_swap_100.c \
			srcs/push_swap_move_tweece_AB.c srcs/push_swap_utils_1.c srcs/push_swap_utils_2.c \
			srcs/push_swap_500.c

OBJECTS	= $(SOURCES:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJECTS)
			@make -C libft/
			@cp libft/libft.a srcs/
			@ar rcs $(NAME) $(OBJECTS)
			$(CC) $(CFLAGS) $(NAME) srcs/libft.a -o push_swap
			make fclean

%.o: srcs/%.c
			$(CC) -c $(CFLAGS) $?

clean:
			@make clean -C libft/
			rm -f $(OBJECTS)

fclean:	
			@make fclean -C libft/
			@make clean
			rm -f $(NAME)
			rm -f srcs/libft.a

re:			fclean all
			rm -f push_swap

.PHONY:		all bonus clean fclean re