/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strncmp.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 17:55:48 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/26 15:13:10 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

#include "../libft.h"
#include "inittest.c"

int		main(int argc, char **argv)
{
	int		ft;
    
	printf("prog: %s\n", argv[0]);
	ft = inittest(argc, "ft_strncmp");
/*
	//Section 1: Functional tests - version 0...
	char	str1[40] = "Hallo12345";
	char	str1b[40] = "Hallo12543";
	char	str0[10] = "";
	char	str99[1000] = "Hallo and very very long";
	unsigned int	len = 3;
	printf("Test 1a: normal, compare %i chars < diff\n", len);
	if (ft == 0)
		printf("strncmp(%s, %s, %i) = %i\n", str1, str99, len, \
		strncmp(str1, str99, len));
	if (ft == 1)
		printf("strncmp(%s, %s, %i) = %i\n", str1, str99, len, \
		ft_strncmp(str1, str99, len));
	
	len = 7;
	printf("Test 1b: normal, compare %i chars > diff\n", len);
	if (ft == 0)
		printf("strncmp(%s, %s, %i) = %i\n", str1, str99, len, \
		strncmp(str1, str99, len));
	if (ft == 1)
		printf("strncmp(%s, %s, %i) = %i\n", str1, str99, len, \
		ft_strncmp(str1, str99, len));

	printf("Test 1c: normal, compare %i chars > diff. Flipped\n", len);	
	if (ft == 0)
		printf("strncmp(%s, %s, %i) = %i\n", str99, str1, len, \
		strncmp(str99, str1, len));
	if (ft == 1)
		printf("strncmp(%s, %s, %i) = %i\n", str99, str1, len, \
		ft_strncmp(str99, str1, len));	
	
	len = 0;
	printf("Test 2: normal, compare %i chars (zero)\n", len);
	if (ft == 0)
		printf("strncmp(%s, %s, %i) = %i\n", str1b, str99, len, \
		strncmp(str1b, str99, len));
	if (ft == 1)
		printf("strncmp(%s, %s, %i) = %i\n", str1b, str99, len, \
		ft_strncmp(str1b, str99, len));
	
	len = 2;
	printf("Test 3: one string is empty, compare %i chars\n", len);
	if (ft == 0)
		printf("strncmp(%s, %s, %i) = %i\n", str1, str0, len, \
		strncmp(str1, str0, len));
	if (ft == 1)
		printf("strncmp(%s, %s, %i) = %i\n", str1, str0, len, \
		ft_strncmp(str1, str0, len));	
*/
	//Compact tests, structured.
	char	test1[50] = "ABCDEcodam";
	char	test2[50] = "ABCDEbrood";
	if (ft == 1)
	{
		printf("Libft: only the sign should be equal\n");
		printf("%i\n", ft_strncmp("acc", "abc", 0));
		printf("%i\n", ft_strncmp("acc", "acc", 0));
		printf("%i\n", ft_strncmp("acc", "acc", 400));
		printf("%i\n", ft_strncmp("", "", 2));
		printf("%i\n", ft_strncmp("", "", 0));
		printf("%i\n", ft_strncmp(test1, test2, 7));
		test1[3] = '\0';
		test2[3] = '\0';
		printf("%i\n", ft_strncmp(test1, test2, 7));
		printf("%i\n", ft_strncmp("abcde", "abcdf", 4));
		printf("%i\n", ft_strncmp("abcde", "abcdf", 5));
		printf("%i\n", ft_strncmp("abcde", "abcdf", 6));
	}
	if (ft == 0)
	{
		printf("Only the sign should be equal\n");
		printf("%i\n", strncmp("acc", "abc", 0));
		printf("%i\n", strncmp("acc", "acc", 0));
		printf("%i\n", strncmp("acc", "acc", 400));
		printf("%i\n", strncmp("", "", 2));
		printf("%i\n", strncmp("", "", 0));
		printf("%i\n", strncmp(test1, test2, 7));
		test1[3] = '\0';
		test2[3] = '\0';
		printf("%i\n", strncmp(test1, test2, 7));
		//To test if n aligns well
		printf("%i\n", strncmp("abcde", "abcdf", 4));
		printf("%i\n", strncmp("abcde", "abcdf", 5));
		printf("%i\n", strncmp("abcde", "abcdf", 6));
	}
	//Test 99: Chars with non ascii chars and \200
	printf("Non ascii tests\n");
	char ts99a[] = "aa\x12\xff\x65\x12\xbd\xde\xad";
	char ts99b[] = "aa\x12\x65";
	if (ft == 0)
		printf("%i\n", strncmp(ts99a, ts99b, 6));
	if (ft == 1)
		printf("%i\n", ft_strncmp(ts99a, ts99b, 6));
	if (ft == 0)
		printf("%i\n", strncmp("abcd\200ef", "abcd\0ef", 6));
	if (ft == 1)
		printf("%i\n", ft_strncmp("abcd\200ef", "abcd\0ef", 6));
/*
	//Special tests, e.g. str = NULL
	//libc and libft seg fault.
	if (ft == 1)
		printf("%i\n", ft_strncmp(NULL, "abc", 3));
	if (ft == 0)
		printf("%i\n", strncmp(NULL, "abc", 3));


	//Special tests, e.g. n = NULL
	//libc and libft do not compile
	if (ft == 1)
		printf("%i\n", ft_strncmp("def", "abc", NULL));
	if (ft == 0)
		printf("%i\n", strncmp("def", "abc", NULL));
*/
}
