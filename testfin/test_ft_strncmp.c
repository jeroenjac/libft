/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strncmp.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 17:55:48 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/12 12:32:46 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

#include "../libft.h"

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
	
	//Section 1: Functional tests - versio 0...
	char	str1[40] = "Hallo12345";
	char	str1b[40] = "Hallo12543";
	char	str0[10] = "";
	char	str99[1000] = "Hallo and very very long";
	unsigned int	len = 3;
	printf("Test 1a: normal, compare %i chars < diff\n", len);
	if (ft == 1)
		printf("strncmp(%s, %s, %i) = %d\n", str1, str99, len, strncmp(str1, str99, len));
	else
		printf("strncmp(%s, %s, %i) = %d\n", str1, str99, len, ft_strncmp(str1, str99, len));
	
	len = 7;
	printf("Test 1b: normal, compare %i chars > diff\n", len);
	if (ft == 1)
		printf("strncmp(%s, %s, %i) = %d\n", str1, str99, len, strncmp(str1, str99, len));
	else
		printf("strncmp(%s, %s, %i) = %d\n", str1, str99, len, ft_strncmp(str1, str99, len));

	printf("Test 1c: normal, compare %i chars > diff. Flipped\n", len);	
	if (ft == 1)
		printf("strncmp(%s, %s, %i) = %d\n", str99, str1, len, strncmp(str99, str1, len));
	else
		printf("strncmp(%s, %s, %i) = %d\n", str99, str1, len, ft_strncmp(str99, str1, len));	
	
	len = 0;
	printf("Test 2: normal, compare %i chars (zero)\n", len);
	if (ft == 1)
		printf("strncmp(%s, %s, %i) = %d\n", str1b, str99, len, strncmp(str1b, str99, len));
	else
		printf("strncmp(%s, %s, %i) = %d\n", str1b, str99, len, ft_strncmp(str1b, str99, len));
	
	len = 2;
	printf("Test 3: one string is empty, compare %i chars\n", len);
	if (ft == 1)
		printf("strncmp(%s, %s, %i) = %d\n", str1, str0, len, strncmp(str1, str0, len));
	else
		printf("strncmp(%s, %s, %i) = %d\n", str1, str0, len, ft_strncmp(str1, str0, len));	
	
	//Compact tests, structured.
	char	test1[50] = "ABCDEcodam";
	char	test2[50] = "ABCDEbrood";
	if (ft == 1)
	{
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
	else
	{
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

/*
	//Special tests, e.g. str = NULL
	//libc and libft seg fault.
	if (ft == 1)
		printf("%i\n", ft_strncmp(NULL, "abc", 3));
	else
		printf("%i\n", strncmp(NULL, "abc", 3));


	//Special tests, e.g. n = NULL
	//libc and libft do not compile
	if (ft == 1)
		printf("%i\n", ft_strncmp("def", "abc", NULL));
	else
		printf("%i\n", strncmp("def", "abc", NULL));
*/
}
