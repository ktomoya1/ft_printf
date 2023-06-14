NAME = libftprintf.a

SRCS = ft_strlen.c \
	ft_strchr.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putnbr_base_set.c \
	ft_printf.c 
	
OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -f
AR = ar
ARFLAGS = rc

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${AR} ${ARFLAGS} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${RMFLAGS} ${OBJS}
fclean: clean
	${RM} ${RMFLAGS} ${NAME}
re: fclean all

.PHONY: all clean fclean re