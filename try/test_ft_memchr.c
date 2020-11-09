/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_memchr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 12:52:58 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/09 13:19:11 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		ft;
	size_t	n;
	int		c;

	//More than 1 argument => No valid input
    //no arguments => work with libc function
    //1 argument => work with libft function
    printf("prog: %s\n", argv[0]);
    if (argc > 2)
    {
        printf("Error w/ testing. Only use 0 or 1 arguments.\n");
        return (0);
    }
    else if (argc == 2)
        ft = 1;
    else
        ft = 0;
    if (ft == 1)
        printf("TESTING LIBFT FUNCTION\n");
    else
        printf("TESTING LIBC FUNCTION\n");
	

	//Test 0: c in src, and within n)
	char	src0[] = "Codam";
	n = 4;
	c = 'd';
	if (ft == 1)
		printf("%s\n", ft_memchr(src0, c, n));
	else
		printf("%s\n", memchr(src0, c, n));
	
	//Test 1: Simple (c in src, and not within n)
	char	src1[] = "Codam";
	n = 2;
	c = 'd';
	if (ft == 1)
		printf("%s\n", ft_memchr(src1, c, n));
	else
		printf("%s\n", memchr(src1, c, n));
	
	//Test 2: Simple (c not in src)
	char	src2[] = "Codam";
	n = 4;
	c = 'q';
	if (ft == 1)
		printf("%s\n", ft_memchr(src2, c, n));
	else
		printf("%s\n", memchr(src2, c, n));
}
