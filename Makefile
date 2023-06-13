NAME = libftprintf.a

SRCS_DIR = ./srcs/
SRCS_FILES = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

SRCS_P = ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putnbr_base_set.c \
	ft_printf.c 
	
SRCS = ${addprefix ${SRCS_DIR}, ${SRCS_FILES}}
SRCS += ${SRCS_P}
OBJS = ${SRCS:.c=.o}

INCDIR = ./includes

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -f
AR = ar
ARFLAGS = rc

.c.o:
	${CC} ${CFLAGS} -c $< -o $@ -I ${INCDIR}

${NAME}: ${OBJS}
	${AR} ${ARFLAGS} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${RMFLAGS} ${OBJS}
fclean: clean
	${RM} ${RMFLAGS} ${NAME}
re: fclean all

.PHONY: all clean fclean re