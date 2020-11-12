/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_isascii.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 20:57:46 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/12 21:04:49 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <limits.h>
#include <ctype.h>

int		main(int argc, char **argv)
{
	int		ft;

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

	//Section 1: Functional tests - running through alphabet++
	int		i;
	int		max;

	i = 0;
	max = 400;
	if (ft == 1)
	{
		while (i <= max)
		{
			printf("isascii(int = %i)? %i\n", i, ft_isascii(i));
			i++;
		}
	}
	else
	{
		while (i <= max)
		{
			printf("isascii(int = %i)? %i\n", i, isascii(i));
			i++;
		}
	}
	
	// Section 2: Specials - int_max, etc.
	if (ft == 1)
	{
		printf("isascii(int = %i)? %i\n", INT_MAX, ft_isascii(INT_MAX));
		printf("isascii(int = %i)? %i\n", INT_MIN, ft_isascii(INT_MIN));
	}
	if (ft == 0)
	{
		printf("isascii(int = %i)? %i\n", INT_MAX, isascii(INT_MAX));
		printf("isascii(int = %i)? %i\n", INT_MIN, isascii(INT_MIN));
	}
	// Section 3: Specials - > int_max, NULL
	// Overflow warning -> error when compile
	// NULL not possible, compile error.
	if (ft == 1)
	{
	//	printf("isascii(int = %i)? %i\n", INT_MAX + 100, ft_isascii(INT_MAX + 100));
	//	printf("isascii(int = %i)? %i\n", NULL, ft_isascii(NULL));
	}
	if (ft == 0)
	{
	//	printf("isascii(int = %i)? %i\n", INT_MAX + 100, isascii(INT_MAX + 100));
	//	printf("isascii(int = %i)? %i\n", NULL, isascii(NULL));
	}
}
