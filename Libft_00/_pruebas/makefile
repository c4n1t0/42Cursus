CFLAGS	= -Wall -Wextra -Werror

CC		= clang

NAME	= -o libftest

all:	
		${CC} ${CFLAGS} ${NAME} mainBzero.c libft.a -L.
		./libftest
re:
		gcc -c ft_*.c
		ar rcs libft.a ft_*.o
clean:
		rm ft_*.o
fclean:
		rm libftest