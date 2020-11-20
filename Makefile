# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jjacobs <jjacobs@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/03 11:48:52 by jjacobs       #+#    #+#                  #
#    Updated: 2020/11/20 17:18:10 by jjacobs       ########   odam.nl          #
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
	  ./ft_strndup.c \

OBJ = $(SRC:.c=.o)
BUILDDIR = obj

CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

all:	$(NAME)

$(NAME): $(SRC)
	gcc $(CFLAGS) -c $(SRC)
	ar -vr $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:		fclean all

.PHONY: clean all
