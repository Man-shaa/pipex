NAME		= pipex

SRCS_DIR	= srcs/

SRCS		= main.c \
			${SRCS_DIR}print.c

_DEPS =		pipex.h

INCL =		./includes/

DEPS =		$(patsubst %,$(INCL)/%,$(_DEPS))

OBJS =		${SRCS:.c=.o}

CC =		clang

RM =		rm -rf

CFLAGS =	-Wall -Werror -Wextra -g

.c.o:		${DEPS} 
		${CC} ${CFLAGS} -g3 -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:		${NAME}

clean:		
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean
		$(MAKE) all -j

.PHONY:		all clean fclean re