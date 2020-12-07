# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jjacobs <jjacobs@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/03 11:48:52 by jjacobs       #+#    #+#                  #
#    Updated: 2020/12/06 23:45:16 by jjacobs       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC = ./ft_memset.c \
	  ./ft_bzero.c \
	  ./ft_memcpy.c \
	  ./ft_memccpy.c \
	  ./ft_memchr.c \
	  ./ft_memmove.c \
	  ./ft_memcmp.c \
	  ./ft_strlen.c \
	  ./ft_strlcpy.c \
	  ./ft_strlcat.c \
	  ./ft_strchr.c \
	  ./ft_strrchr.c \
	  ./ft_strnstr.c \
	  ./ft_strncmp.c \
	  ./ft_atoi.c \
	  ./ft_isalpha.c \
	  ./ft_isdigit.c \
	  ./ft_isalnum.c \
	  ./ft_isascii.c \
	  ./ft_isprint.c \
	  ./ft_toupper.c \
	  ./ft_tolower.c \
	  ./ft_calloc.c \
	  ./ft_strdup.c \
	  ./ft_substr.c \
	  ./ft_strjoin.c \
	  ./ft_strtrim.c \
	  ./ft_split.c \
	  ./ft_itoa.c \
	  ./ft_strmapi.c \
	  ./ft_putchar_fd.c \
	  ./ft_putstr_fd.c \
	  ./ft_putendl_fd.c \
	  ./ft_putnbr_fd.c
 
SRC_BONUS = ./ft_lstnew.c \
			./ft_lstadd_front.c \
			./ft_lstsize.c \
			./ft_lstlast.c \
			./ft_lstadd_back.c \
			./ft_lstdelone.c \
			./ft_lstclear.c \
			./ft_lstiter.c \
			./ft_lstmap.c

SRC_EXTRA = ./ft_strndup.c

NAME = libft.a

OBJ_FILES_REG = $(SRC:.c=.o)
OBJ_FILES_BONUS = $(SRC_BONUS:.c=.o)
OBJ_FILES_EXTRA = $(SRC_EXTRA:.c=.o)

HEADER_FILES = libft.h
CFLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
OBJ_FILES = $(OBJ_FILES_REG) $(OBJ_FILES_EXTRA) $(OBJ_FILES_BONUS)
else
OBJ_FILES = $(OBJ_FILES_REG) $(OBJ_FILES_EXTRA)
endif

all:	$(NAME)

$(NAME): $(OBJ_FILES)
	ar -vr $@ $^

# flags used: -v for extra output, -r for replace files in arch.
# -c can be used to supress archive creating message. Not needed. 

bonus:
	$(MAKE) WITH_BONUS=1 all

%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ_FILES_REG) $(OBJ_FILES_EXTRA) $(OBJ_FILES_BONUS)

fclean:	clean
	rm -f $(NAME)

re:		fclean all

.PHONY: all bonus clean fclean re
