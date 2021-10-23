SRCS		= ft_format_chars.c ft_format_decimals.c ft_format_hexadecimals.c \
			  ft_printf.c ft_printf_utils.c

OBJS		= ${SRCS:.c=.o}

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
NAME		= libftprintf.a

.c.o :		
			${CC} ${CFLAGS} -I. -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all :		${NAME}

clean :	
			rm -f ${OBJS}
				
fclean :	clean
			rm -f ${NAME}
			
re :		fclean all

.PHONY :	all clean fclean make re
