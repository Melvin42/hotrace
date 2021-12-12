SRCS	= ft_bzero.c \
		  ft_hash_add_back.c \
		  ft_hashnew.c \
		  ft_lstadd_front.c \
		  ft_lstlast.c \
		  ft_lstsize.c \
		  ft_strcmp.c \
		  ft_strdup.c \
		  hotrace_tools.c \
		  ft_calloc.c \
		  ft_hashlast.c \
		  ft_lstadd_back.c \
		  ft_lstclear.c \
		  ft_lstnew.c \
		  ft_memset.c \
		  ft_strcpy.c \
		  ft_strlen.c \
		  hotrace.c \
		  ft_write_error.c \
		  hotrace_utils.c

OBJS	= ${SRCS:.c=.o}

NAME	= hotrace

CC		= cc

RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror -g3

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${OBJS}
			${CC} -o ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
