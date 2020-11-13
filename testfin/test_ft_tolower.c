/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_tolower.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 21:59:40 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/13 08:58:31 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include "inittest.c"

int     inittest(int argc, char *ftname);

int     main(int argc, char **argv)
{
    int     ft;

    printf("prog: %s\n", argv[0]);
    ft = inittest(argc, "ft_tolower");

	//Section 1: Functional tests: all ascii chars

	int		i = 32;
	int		imax = 127;

	while (i <= imax)
	{
		if (ft == 1)
			printf("i = %i - tolower(%c) = %c\n", i, (char)i, ft_tolower((char)i));
		if (ft == 0)
			printf("i = %i - tolower(%c) = %c\n", i, (char)i, tolower((char)i));
		i++;
	}
	
	//Section 2: Corner cases 0 / INT MIN / MAX etc.
    //Not possible to compare these using diff (gives binary output)
    int     passed1 = 0;

    if (ft == 2)
    {
        passed1 = ft_tolower(0) == tolower(0);
        printf("tolower(0) equal? \t\t%i\n", passed1);
        passed1 = ft_tolower(INT_MAX) == tolower(INT_MAX);
        printf("tolower(max) equal? \t\t%i\n", passed1);
        passed1 = ft_tolower(INT_MIN) == tolower(INT_MIN);
        printf("tolower(min) equal? \t\t%i\n", passed1);
        passed1 = ft_tolower(INT_MAX + 200) == tolower(INT_MAX + 200);
        printf("tolower(max + 200) equal? \t%i\n", passed1);
    }
}
