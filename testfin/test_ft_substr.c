/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_substr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 14:21:51 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/17 10:38:06 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "inittest.c"

#include "../libft.h"

int		main(int argc, char **argv)
{
	int		ft;

	printf("prog: %s\n", argv[0]);
	ft = inittest(argc, "ft_substr");

	int		start;
	int		len;	
	
	// t1: simple tests
	if (ft ==  1)
	{
		char	*direct;

		direct = ft_substr("1234567890abcd", 6, 5);
		printf("direct: %s\n", direct);
	
		char	a1[11] = "abcde12345";
		char	*b1;
	
		start = 5;
		len = 50;
		printf("a1: %s\n (start = %d, len = %d)\n", a1, start, len);
		b1 = ft_substr(a1, (unsigned int) start, (size_t) len);
		printf("result: %s\n", b1);

		char	a2[100] = "I would like to see part of this string";
		char	*b2;
		start = 20;
		len = 10000;
	
		printf("a2: %s\n (start = %d, len = %d)\n", a2, start, len);
		b2 = ft_substr(a2, (unsigned int) start, (size_t) len);
		printf("result: %s\n", b2);
	}
	
	// t2: check test / compare with right answerss
	if (ft == 3)
	{	
		char	a3[] = "abcdef";
		start = 3;
		len = 4;
		printf ("Test 1 (substr of last part): ");
		if (ft_strncmp("def", ft_substr(a3, start, len), len) == 0)
			printf("\t\tSucces\n");
		else
		{
			printf("Failed\n");
			printf("substr: %s\n", ft_substr(a3, start, len));
		}
		start = 0;
		len = 6;
		printf ("Test 2 (substr = complete string): ");
		if (ft_strncmp("abcdef", ft_substr(a3, start, len), 10) == 0)
			printf("\tSucces\n");
		else
		{
			printf("Failed\n");
			printf("substr: %s\n", ft_substr(a3, start, 10));
		}
		start = 4;
		len = 0;
		printf ("Test 3 (len = 0): ");
		if (ft_strncmp("", ft_substr(a3, start, len), 10) == 0)
			printf("\t\t\tSucces\n");
		else
		{
			printf("Failed\n");
			printf("substr: %s\n", ft_substr(a3, start, len));
		}
		start = 13;
		len = 3;
		printf ("Test 4 (Start > Size of s): ");
		if (ft_strncmp("", ft_substr(a3, start, len), 20) == 0)
			printf("\t\tSucces\n");
		else
		{
			printf("Failed\n");
			printf("substr: %s\n", ft_substr(a3, start, len));
		}
	}
	//t3: wrong input - shouldnt break?
	if (ft == 1)
	{
		char	wr[20] = "a1c4e6";
		
		printf("Part 3a: Test for negative start\n");
		printf("%s\n", ft_substr(wr, -2, 2));
		printf("Part 3b: Test for negative len\n");
		printf("%s\n", ft_substr(wr, 1, -1));
		printf("Part 3c: Test for string = NULL\n");
		ft_substr(NULL, 2, 2);
	}
}
