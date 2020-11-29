/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_itoa.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 16:59:14 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/27 11:32:16 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include "inittest.c"

#include <limits.h>
#include <string.h>
#include <stdlib.h>

/*
** Testing modes
** 0: Prototyping + testing digit count
** 1: Structured testing, all different cases; print the output
** 3: Structured testing, checking failed/passed
**		3a: manual w. output
		3b: using atoi function
		3c: using ft_atoi function, iterating through a range
*/

//Testfunctions
void	test_itoa_man(int i, char *result);
void	test_itoa_atoi(int i);
void	test_itoa_ft_atoi(int i);

int		main(int argc, char **argv)
{
	int		ft;

	printf("prog: %s\n", argv[0]);
	ft = inittest(argc, "ft_itoa");
	
	if (ft == 0)
	{
		char	*ret;
		ret = ft_itoa(12);
		printf("%s\n", ret);
	}

	if (ft == 1)
	{
		printf("%s\n", ft_itoa(0));
		printf("%s\n", ft_itoa(-7));
		printf("%s\n", ft_itoa(5));
		printf("%s\n", ft_itoa(42));
		printf("%s\n", ft_itoa(1123));
		printf("%s\n", ft_itoa(-10000));
		printf("%s\n", ft_itoa(INT_MAX));
		printf("%s\n", ft_itoa(INT_MIN));
	}
	if (ft == 3)
	{
		printf("Part 1: test against expected output\n");
		test_itoa_man(-1, "-1");
		test_itoa_man(0, "0");
		test_itoa_man(1, "1");
		test_itoa_man(42, "42");
		test_itoa_man(-777, "-777");
		test_itoa_man(INT_MAX, "2147483647");
		
		printf("\nPart 2: test using atoi\n");
		test_itoa_atoi(42);
		test_itoa_atoi(INT_MAX);
		
		printf("\nPart 3a: test using ft_atoi - specific cases\n");
		test_itoa_ft_atoi(INT_MIN);
		test_itoa_ft_atoi(0);
		test_itoa_ft_atoi(5);
		test_itoa_ft_atoi(42);
		test_itoa_ft_atoi(INT_MAX);
		
		int		j = -2020;
		int		jmax = 2020;
		printf("\nPart 3b: test using ft_atoi - iterate from %i to %i\n", j, jmax);
		printf("Only failed cases are printed...\n");
		while (j < jmax)
		{
			if (ft_atoi(ft_itoa(j)) != j)
				printf("Test for n = %-15iFailed\n", j);
			j++;
		}
	}
	if (ft == 5)
	{
		//can't compile?
		//ft_itoa(INT_MAX + 500);
	}
}

void	test_itoa_man(int i, char *result)
{
	printf("Test for n = %-15i", i);
	if (strcmp(ft_itoa(i), result) == 0)
		printf("Passed\n");
	else
		printf("Failed\n");
}

void	test_itoa_atoi(int i)
{
	printf("Test for n = %-15i", i);
	if (atoi(ft_itoa(i)) == i)
		printf("Passed\n");
	else
		printf("Failed\n");
}

void	test_itoa_ft_atoi(int i)
{
	if (ft_atoi(ft_itoa(i)) != i)
	{
		printf("Test for n = %-15i", i);
		printf("Failed\n");
	}
	else
	{
		printf("Test for n = %-15i", i);
		printf("Passed\n");
	}
}
