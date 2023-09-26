NAME			=	ssd

PRE				=	srcs/
SRCS			=	ssd.c	\

CFILES			=	${addprefix ${PRE}, ${SRCS}}
OBJS			=	${CFILES:.c=.o}

INC				=	includes
LIBS			=	libs

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror

LIBC			=	ar rcs

REMOVE			=	rm -f

all:				${NAME}

%.o : %.c
					${CC} ${CFLAGS} -c $< -o $@ -I ${LIBS}/libmjkio -I ${INC}

${NAME}:			${OBJS}
					@${MAKE} -C ${LIBS}/libmjkio
					${CC} ${OBJS} -o ${NAME} -L ${LIBS}/libmjkio -lmjkio

clean:
					${REMOVE} ${OBJS}
					@${MAKE} -C ${LIBS}/libmjkio clean

fclean:
					@${MAKE} clean
					${REMOVE} ${NAME}
					@${MAKE} -C ${LIBS}/libmjkio fclean

re:
					@${MAKE} fclean
					@${MAKE}

.PHONY:				all clean fclean re