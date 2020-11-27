/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strjoin.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 18:46:03 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/26 18:35:17 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "inittest.c"
#include <string.h>

#include "../libft.h"

/*
** Testing modes
** 1. Simple testing when coding
** 3. Comparing to expected output
** 5. Error when arg is NULL
*/

int		main(int argc, char **argv)
{
	int		ft;

	printf("prog: %s\n", argv[0]);
	ft = inittest(argc, "ft_strjoin");
	
	// t1: simple tests
	if (ft ==  1)
	{
		char	*direct;

		direct = ft_strjoin("1234567890", "abcd");
		printf("direct: %s\n", direct);
	
		char	a1[] = "abcde12345qqq";
		char	b1[] = "abcde12345";
		char	*c1;
	
		c1 = ft_strjoin(a1, b1);
		printf("result: %s\n", c1);
	}
	
	char	a3[] = "ab";
	char	b3[] = "123";
	
	// t2: check test / compare with right answerss
	if (ft == 3)
	{	
		printf ("Test 1 join: ");
		if (ft_strncmp("ab123", ft_strjoin(a3, b3), 200) == 0)
			printf("\t\tSucces\n");
		else
			printf("Failed\n");
		printf ("Test 2 join 1x empty: ");
		if (ft_strncmp("ab", ft_strjoin(a3, ""), 200) == 0)
			printf("\tSucces\n");
		else
			printf("Failed\n");
		printf ("Test 3 join 2x empty: ");
		if (ft_strncmp("", ft_strjoin("", ""), 200) == 0)
			printf("\tSucces\n");
		else
			printf("Failed\n");
		char *end = ft_strjoin("abc", "def");
		char *tst = "abcdef";
		printf ("Test 4 check j[len] = 0");
		if (strcmp(end, tst) == 0)
			printf("\tSucces\n");
		else
			printf("Failed\n");
		printf("%i\n", strcmp(end, tst));
	}
	//t3: wrong input
	if (ft == 5)
	{
		printf("Part 3c: Test for string = NULL\n");
		printf("%s", ft_strjoin(a3, NULL));
	}
}
