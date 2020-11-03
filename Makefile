# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jjacobs <jjacobs@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/03 11:48:52 by jjacobs       #+#    #+#                  #
#    Updated: 2020/11/03 20:15:39 by jjacobs       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC = ./ft_strlen.c \
	  ./ft_strncmp.c \
	  ./ft_memset.c \
	  ./ft_bzero.c \
	  ./ft_memcpy.c \

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
