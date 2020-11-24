/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_putchar_fd.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 01:11:50 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/24 01:26:30 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "inittest.c"
#include "../libft.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		ft;

	printf("prog: %s\n", argv[0]);
	ft = inittest(argc, "ft_putchar_fd");
	
	int		fd;
	char	c;

	fd = 1;
	c = 'J';

	ft_putchar_fd(c, fd);

	char	filename[20] = "test1.txt";
	
	fd = open(filename, O_RDWR);
	printf("Try to write to fd = %i\n", fd);
	ft_putchar_fd(c, fd);
	close(fd);
}
