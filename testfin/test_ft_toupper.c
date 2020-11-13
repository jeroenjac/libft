/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_toupper.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 21:59:40 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/13 09:03:20 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include "inittest.c"

int		inittest(int argc, char *ftname);

int		main(int argc, char **argv)
{
	int		ft;

    printf("prog: %s\n", argv[0]);
	ft = inittest(argc, "ft_toupper");
	
	//Section 1: Functional tests: all ascii chars
	int		i = 32;
	int		imax = 50; //127;

	while (i <= imax)
	{
		if (ft == 1)
			printf("i = %i - to_upper(%c) = %c\n", i, (char)i, ft_toupper((char)i));
		if (ft == 0)
			printf("i = %i - to_upper(%c) = %c\n", i, (char)i, toupper((char)i));
		i++;
	}

	//Section 2: Corner cases 0 / INT MIN / MAX etc.
	//Not possible to compare these using diff (gives binary output)
	int		passed1 = 0;
	
	if (ft == 2)
	{
		passed1 = ft_toupper(0) == toupper(0);
		printf("toupper(0) equal? \t\t%i\n", passed1);
		passed1 = ft_toupper(INT_MAX) == toupper(INT_MAX);
		printf("toupper(max) equal? \t\t%i\n", passed1);
		passed1 = ft_toupper(INT_MIN) == toupper(INT_MIN);
		printf("toupper(min) equal? \t\t%i\n", passed1);
		passed1 = ft_toupper(INT_MAX + 200) == toupper(INT_MAX + 200);
		printf("toupper(max + 200) equal? \t%i\n", passed1);
	}
}
