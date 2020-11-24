/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_putchar_fd.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 01:11:50 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/24 18:45:36 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "inittest.c"
#include "../libft.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

/*
** TESTMODES
** 0. Random testing
** 1. Let ft function write char to file
*/

int		main(int argc, char **argv)
{
	int		ft;

	printf("prog: %s\n", argv[0]);
	ft = inittest(argc, "ft_putchar_fd");

	int		fd;
	char	c;
	
	if (ft == 1)
	{
		fd = 1;
		c = 'C';
		ft_putchar_fd(c, fd);
	}
	if (ft == 1)
	{
		char	filename[30] = "output_ft_putchar_fd";	
		fd = open(filename, O_WRONLY |  O_APPEND | O_CREAT, 0644);
		if (fd == -1)
			printf("Test error: could not create/open/write file\n");	
		c = 'Y';
		//printf("Try to write '%c' to fd = %i\n", c, fd);
		ft_putchar_fd(c, fd);
		close(fd);

		//TESTING FOR FT_PUTSTR
		printf("\n!! TESTING FT_PUTSTR_FD (print filename):\n");
		ft_putstr_fd(filename, 1);
	}
	if (ft == 1)
	{
		char	filename2[30] = "output_ft_putstr_fd";	
		fd = open(filename2, O_WRONLY |  O_APPEND | O_CREAT, 0644);
		if (fd == -1)
			printf("Test error: could not create/open/write file\n");	
		ft_putstr_fd("PUTSTR: Codam: Working on libft\n", fd);
		close(fd);
	}
	if (ft == 1)
	{
		printf("\n!! TESTING FT_PUTENDL_FD (print some non ending line):\n");
		ft_putendl_fd("Codam and a newline", 1);
		printf("This should be on a new line");
		char	filename3[30] = "output_ft_putendl_fd";	
		fd = open(filename3, O_WRONLY | O_CREAT, 0644);
		if (fd == -1)
			printf("Test error: could not create/open/write file\n");	
		ft_putendl_fd("PUTENDL: String not ending with a new line", fd);
		//ft_putchar_fd('\n', fd);
		close(fd);
	}
	if (ft == 1)
	{
		printf("\n!! TESTING FT_PUTNBR_FD (print a num):\n");
		ft_putnbr_fd(2020, 1);
		char	filename4[30] = "output_ft_putnbr_fd";	
		fd = open(filename4, O_WRONLY | O_CREAT, 0644);
		if (fd == -1)
			printf("Test error: could not create/open/write file\n");	
		ft_putnbr_fd(INT_MIN, fd);
		close(fd);
	}
}
