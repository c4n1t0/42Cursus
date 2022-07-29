# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/26 01:08:42 by jaromero          #+#    #+#              #
#    Updated: 2022/07/29 19:49:09 by jaromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= srcs/ft_push_swap.a

NAME_BONUS = bonus/checker.a

SOURCES	=	srcs/push_swap_move_A.c srcs/push_swap_source_validator.c srcs/push_swap_utils_0.c srcs/push_swap.c \
			srcs/push_swap_move_B.c srcs/push_swap_app_0.c srcs/push_swap_move_tweece.c srcs/push_swap_loop.c \
			srcs/push_swap_move_tweece_AB.c srcs/push_swap_utils_1.c srcs/push_swap_utils_2.c \
			srcs/push_swap_app_1.c

BSOURCES =	bonus/checker_bonus.c bonus/push_swap_move_A_silent.c bonus/push_swap_move_B_silent.c \
			bonus/push_swap_move_tweece_AB_silent.c bonus/push_swap_move_tweece_silent.c \
			bonus/push_swap_source_validator.c bonus/push_swap_utils_0.c

OBJECTS	= $(SOURCES:.c=.o)

BOBJECTS	= $(BSOURCES:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJECTS)
			##### Compilando LIBFT #####
			@make -C libft/ --silent
			@cp libft/libft.a srcs/
			@ar rcs $(NAME) $(OBJECTS)
			$(CC) $(CFLAGS) $(NAME) srcs/libft.a -o push_swap

%.o: srcs/%.c
			$(CC) -c $(CFLAGS) $?

bonus:		$(BOBJECTS)
			##### Compilando LIBFT #####
			@make -C libft/
			@cp libft/libft.a bonus/
			@ar rcs $(NAME_BONUS) $(BOBJECTS)
			$(CC) $(CFLAGS) $(NAME_BONUS) bonus/libft.a -o checker

%.o: bonus/%.c
			$(CC) -c $(CFLAGS) $?


clean:
			@make clean -C libft/
			rm -f $(OBJECTS)
			rm -f $(BOBJECTS)

fclean:	
			@make fclean -C libft/
			@make clean
			rm -f $(NAME)
			rm -f $(NAME_BONUS)
			rm -f srcs/libft.a
			rm -f bonus/libft.a
			rm -f push_swap
			rm -f checker

re:			fclean all
			
.PHONY:		all bonus clean fclean re