# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jjacobs <jjacobs@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/03 11:48:52 by jjacobs       #+#    #+#                  #
#    Updated: 2020/11/09 22:23:55 by jjacobs       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC = ./ft_strlen.c \
	  ./ft_strncmp.c \
	  ./ft_memset.c \
	  ./ft_bzero.c \
	  ./ft_memcpy.c \
	  ./ft_memccpy.c \
	  ./ft_memchr.c \
	  ./ft_memmove.c \
	  ./ft_memcmp.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

$(NAME): $(SRC)
	gcc $(CFLAGS) -c $(SRC)
	ar -vq $(NAME) $(OBJ)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:		fclean all
