# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jjacobs <marvin@codam.nl>                    +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/26 13:41:18 by jjacobs       #+#    #+#                  #
#    Updated: 2020/10/26 16:29:52 by jjacobs       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC = ./part1.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror
NAME = part1.a

$(NAME): 	$(OBJ)
			gcc -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:		fclean all
