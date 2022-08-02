# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 17:21:57 by jaromero          #+#    #+#              #
#    Updated: 2022/08/02 12:58:17 by jaromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER	=	minitalk_server.a

NAME_CLIENT	=	minitalk_client.a

SOURCES_SERVER	=	server.c

SOURCES_CLIENT	=	client.c

OBJECTS_SERVER	=	$(SOURCES_SERVER:.c=.o)

OBJECTS_CLIENT	=	$(SOURCES_CLIENT:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME_SERVER)

$(NAME_SERVER):	$(OBJECTS_SERVER)
				##### Compilando LIBFT #####
				@make -C libft/ --silent
				@cp libft/libft.a .
				@ar rcs $(NAME_SERVER) $(OBJECTS_SERVER)
				$(CC) $(CFLAGS) $(NAME_SERVER) libft.a -o server
				ar rcs minitalk_client.a client.c
				gcc -Wall -Wextra -Werror client.c libft.a minitalk_client.a -o client
			

$(NAME_CLIENT):	$(OBJECTS_CLIENT)
				@ar rcs $(NAME_CLIENT) $(OBJECTS_CLIENT)
				$(CC) $(CFLAGS) $(NAME_CLIENT) libft.a -o client

%.o: %.c
			$(CC) -c $(CFLAGS) $?

clean:
			@make clean -C libft/
			rm -f $(OBJECTS_CLIENT)
			rm -f $(OBJECTS_SERVER)

fclean:	
			@make fclean -C libft/
			@make clean
			rm -f $(NAME_CLIENT)
			rm -f $(NAME_SERVER)
			rm -f libft.a
			rm -f server
			rm -f client

re:			fclean all
			
.PHONY:		all bonus clean fclean re