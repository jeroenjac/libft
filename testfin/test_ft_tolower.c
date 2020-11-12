/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_tolower.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 21:59:40 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/12 22:44:35 by jjacobs       ########   odam.nl         */
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

	//Section 1: Functional tests
	// - Print al ascii chars
	// - to upper these

	int		i = 32;
	int		imax = 127;

	while (i <= imax)
	{
		if (ft == 1)
			printf("i = %i - tolower(%c) = %c\n", i, (char)i, ft_tolower((char)i));
		else
			printf("i = %i - tolower(%c) = %c\n", i, (char)i, tolower((char)i));
		i++;
	}
/*
	//Section 2: INT MAX/MIN
	i = INT_MAX;
	if (ft == 1)
		printf("i = %i - tolower(%c) = %c\n", i, (char)i, ft_tolower((char)i));
	else
		printf("i = %i - tolower(%c) = %c\n", i, (char)i, tolower((char)i));
	i = INT_MIN;
	if (ft == 1)
		printf("i = %i - tolower(%c) = %c\n", i, (char)i, ft_tolower((char)i));
	else
		printf("i = %i - tolower(%c) = %c\n", i, (char)i, tolower((char)i));
*/
}
