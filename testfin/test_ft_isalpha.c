/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_isalpha.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 09:43:19 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/12 10:06:47 by jjacobs       ########   odam.nl         */
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
			printf("isalpha(int = %i)? %i\n", i, ft_isalpha(i));
			i++;
		}
	}
	else
	{
		while (i <= max)
		{
			printf("isalpha(int = %i)? %i\n", i, isalpha(i));
			i++;
		}
	}
	
	// Section 2: Specials - int_max, etc.
	if (ft == 1)
	{
		printf("isalpha(int = %i)? %i\n", INT_MAX, ft_isalpha(INT_MAX));
		printf("isalpha(int = %i)? %i\n", INT_MIN, ft_isalpha(INT_MIN));
	}
	if (ft == 0)
	{
		printf("isalpha(int = %i)? %i\n", INT_MAX, isalpha(INT_MAX));
		printf("isalpha(int = %i)? %i\n", INT_MIN, isalpha(INT_MIN));
	}
	// Section 3: Specials - > int_max, NULL
	// Overflow warning -> error when compile
	// NULL not possible, compile error.
	if (ft == 1)
	{
	//	printf("isalpha(int = %i)? %i\n", INT_MAX + 100, ft_isalpha(INT_MAX + 100));
	//	printf("isalpha(int = %i)? %i\n", NULL, ft_isalpha(NULL));
	}
	if (ft == 0)
	{
	//	printf("isalpha(int = %i)? %i\n", INT_MAX + 100, isalpha(INT_MAX + 100));
	//	printf("isalpha(int = %i)? %i\n", NULL, isalpha(NULL));
	}
}
