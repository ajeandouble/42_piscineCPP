SRCS = phoneBook.cpp
	
CPP = g++
CFLAGS = -c -Wall -Werror -Wextra
OBJS = ${SRCS:.cpp=.o}
NAME = phoneBook

.c.o:
	${CPP} ${CFLAGS} $< -o ${<:c=o}

${NAME}:	${OBJS}
			${CPP} ${OBJS} -o ${NAME}

all:	${NAME}

clean:
			rm -f ${OBJS}

fclean:	clean
			rm -f ${NAME}

re:			fclean all

.PHONY:	all clean fclean re
