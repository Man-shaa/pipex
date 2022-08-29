NAME		= pipex

SRCS_DIR	= mandatory_srcs/

BONUS_SRCS_DIR	= bonus_srcs/

SRCS		= main.c \
			${SRCS_DIR}init.c \
			${SRCS_DIR}parsing.c \
			${SRCS_DIR}process.c \
			${SRCS_DIR}split.c \
			${SRCS_DIR}utils.c

SRCS_BONUS	= 	main_bonus.c \
				${BONUS_SRCS_DIR}init.c \
				${BONUS_SRCS_DIR}parsing.c \
				${BONUS_SRCS_DIR}process.c \
				${BONUS_SRCS_DIR}split.c \
				${BONUS_SRCS_DIR}utils_list.c \
				${BONUS_SRCS_DIR}utils.c

_DEPS		= pipex.h

INCL		= ./includes/

DEPS		= $(patsubst %,$(INCL)/%,$(_DEPS))

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

CC			= clang

RM			= rm -rf

CFLAGS		= -Wall -Werror -Wextra -g3

.c.o:		${DEPS}
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

bonus:		${OBJS_BONUS}
		${CC} ${CFLAGS} ${OBJS_BONUS} -o ${NAME}

all:		${NAME}

clean:		
		${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
		${RM} ${NAME}

re:			fclean
		$(MAKE) all -j

.PHONY:		all clean fclean re