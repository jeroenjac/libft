# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:      :+:    :+:    #
#                                                      +:+                     #
#    By: jjacobs <marvin@codam.nl>                    +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/26 13:41:18 by jjacobs       #+#    #+#                  #
#    Updated: 2020/10/28 21:04:36 by jjacobs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./ft_strlen.c \
	  ./ft_strncmp.c \
	  ./ft_memset.c \

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
