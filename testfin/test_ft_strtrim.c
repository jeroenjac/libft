/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strtrim.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 12:54:05 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/30 21:07:43 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "inittest.c"

#include "../libft.h"

/*
 * TESTING MODES
 * 1. Simple / explicit
 * 3. Compare (incl. set = NULL)
 * 5. Error Break with s = NULL
*/

void	testtrim(char *in, char *set, char *out);

int		main(int argc, char **argv)
{
	int		ft;

	printf("prog: %s\n", argv[0]);
	ft = inittest(argc, "ft_strtrim");
	
	// t1: simple tests
	if (ft ==  1)
	{
		char	*direct;
		char	c = 'a';

		printf("result strchr = %s\n", ft_strchr("ab", (int)c));
		direct = ft_strtrim("        ", " ");
		printf("direct: %s\n", direct);
	
		char	s1[] = "abbabbba";
		char	set1[] = "a";
		char	*res1;
	
		printf("trim \"%s\" from \"%s\":\n", s1, set1);
		res1 = ft_strtrim(s1, set1);
		printf("result: %s\n", res1);
	}
	
	// t2: check test / compare with correct answerss
	if (ft == 3)
	{	
		char	s3i[100];
		char	s3a[100];
		char	st3[10];

		//Keeping 1x 'exlicit testing procedure' to validate test function
		ft_strlcpy(s3i, "a1234b", 100);		//The input
		ft_strlcpy(st3, "ab", 100);			//The trim set to use
		ft_strlcpy(s3a, "1234", 100);		//The expected result
		printf ("Test strtrim \"%s\" using set=\"%s\"): ", s3i, st3);
		if (ft_strncmp(s3a, ft_strtrim(s3i, st3), 150) == 0)
			printf("\t\t\tSucces\n");
		else
		{
			printf("\t\t\tFailed\n");
			printf("result: %s\n", ft_strtrim(s3i, st3));
		}
		
		//Tests using test functions "testtrim()":
		//		input		charset		expected output
		testtrim("a1234b",	"ab",		"1234");
		testtrim("ab",		"",			"ab");
		testtrim("aaaa",	"a",		"");
		testtrim("abcba",	"aaaaa",	"bcb");
		testtrim("qqabcqq", "abc",		"qqabcqq");
		testtrim("abqqcd",	"abcd",		"qq");
		testtrim("abqqcd",	"12",		"abqqcd");
		testtrim("abqqqq",	"ab",		"qqqq");
		testtrim("qqqaaab",	"ab",		"qqq");
		testtrim("baqqqa",	"a\0b",		"baqqq");
		testtrim("abc1234",	"abc",		"1234");
		testtrim("abc",		NULL,		"abc");
		testtrim("   ",		" ",		""); //sometimes error/abort with warmachine.
		testtrim("abbaabba",	"ab",	"");	
	}
	if (ft == 5)	
	{
		//testtrim does not work with s = NULL, due to strncmp not working with NULL.
		char	setw[20] = "set";
		printf("Test for string = NULL (expected: (null)\n");
		if (ft_strtrim(NULL, setw) == NULL)
			printf("\t\t\t\t\t\t\tSucces\n");
		else
		{
			printf("\t\t\t\t\t\t\tFailed\n");
			printf("result: %s\n", ft_strtrim(NULL, setw));
		}
	}
}

void	testtrim(char *in, char *set, char *out)
{
		printf("Test strtrim \"%s\" using set = \"%s\" == \"%s\"?\n", in, set, out);
		if (ft_strncmp(out, ft_strtrim(in, set), 150) == 0)
			printf("\t\t\t\t\t\t\tSucces\n");
		else
		{
			printf("\t\t\t\t\t\t\tFailed\n");
			printf("result: %s\n", ft_strtrim(in, set));
		}
}
