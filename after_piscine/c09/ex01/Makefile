NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c

OBJS = ${SRCS:.c=.o}

.c.o :
	${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	ar -rc ${NAME} *.o

clean :
	rm -f ${NAME} ${OBJS}
	ranlib ${NAME}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
