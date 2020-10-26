# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jjacobs <marvin@codam.nl>                    +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/26 13:41:18 by jjacobs       #+#    #+#                  #
#    Updated: 2020/10/26 14:13:38 by jjacobs       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = part1.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: part1.c
	$(CC) $(CFLAGS) $(NAME) -o libft.a

clean:
	$(RM) *.o



fclean: clean
	$(RM) *.o
