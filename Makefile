NAME			=	ssd

SRCSPATH		=	srcs
SRCS			=	main.c	\
					ssd.c	\

CFILES			=	${addprefix ${SRCSPATH}/, ${SRCS}}
OBJS			=	${CFILES:.c=.o}

INC				=	includes

LIBSPATH		=	libs
LIBSPRE			=	lib
LIBS			=	mjkio	\
					mjkstd	\

LIBFILES		=	${addprefix ${LIBSPATH}/, ${addprefix ${LIBSPRE}, ${LIBS}}}

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror

LIBC			=	ar rcs

REMOVE			=	rm -f

all:				${NAME}

%.o : %.c
					${CC} ${CFLAGS} -c $< -o $@ -I ${LIBSPATH}/libmjkio -I ${LIBSPATH}/libmjkstd -I ${INC}

${NAME}:			${OBJS}
					@${MAKE} -C ${LIBSPATH}/libmjkio
					@${MAKE} -C ${LIBSPATH}/libmjkstd
					${CC} ${OBJS} -o ${NAME} -L ${LIBSPATH}/libmjkio -lmjkio -L ${LIBSPATH}/libmjkstd -lmjkstd

clean:
					${REMOVE} ${OBJS}
					@${MAKE} -C ${LIBSPATH}/libmjkio clean

fclean:
					@${MAKE} clean
					${REMOVE} ${NAME}
					${REMOVE} nand
					${REMOVE} result
					@${MAKE} -C ${LIBSPATH}/libmjkio fclean
					@${MAKE} -C ${LIBSPATH}/libmjkstd fclean

re:
					@${MAKE} fclean
					@${MAKE}

.PHONY:				all clean fclean re