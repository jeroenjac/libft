# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jjacobs <marvin@codam.nl>                    +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/26 13:41:18 by jjacobs       #+#    #+#                  #
#    Updated: 2020/10/26 19:58:29 by jjacobs       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC = ./fts/ft_strlen.c \
	  ./fts/ft_strncmp.c \
	  ./fts/ft_memset.c \
	  ./testlibft.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

$(NAME): 	$(OBJ)
			gcc -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:		fclean all
