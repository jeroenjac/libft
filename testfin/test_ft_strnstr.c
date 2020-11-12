/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strncmp.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 17:55:48 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/12 12:22:59 by jjacobs       ########   odam.nl         */
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
	
	//Compact tests, structured.
	char	test0[50] = "ABCDE-neodle-12345";
	char	test1[50] = "ABCDE-needle-12345";
	char	test2[50] = "ABCDE-needle-12345-secondneedle-678";
	char	lookfor[10] = "needle";
	int		len = 50;
	int		len_short = 11; //This is 1 to short
	if (ft == 1)
	{
		printf("%s\n", ft_strnstr(test0, lookfor, len));
		//it should not adjust input pointers
		printf("bf = %s\n", test1);
		printf("%s\n", ft_strnstr(test1, lookfor, len));
		printf("af = %s\n", test1);
		printf("%s\n", ft_strnstr(test2, lookfor, len));
		printf("%s\n", ft_strnstr(test0, lookfor, len_short));
		printf("%s\n", ft_strnstr(test1, lookfor, len_short));
		printf("%s\n", ft_strnstr(test0, "A", 0));
		printf("%s\n", ft_strnstr(test0, "A", 1));
	}
	else
	{
		printf("%s\n", strnstr(test0, lookfor, len));
		//it should not adjust input pointers
		printf("bf = %s\n", test1);
		printf("%s\n", strnstr(test1, lookfor, len));
		printf("af = %s\n", test1);
		printf("%s\n", strnstr(test2, lookfor, len));
		printf("%s\n", strnstr(test0, lookfor, len_short));
		printf("%s\n", strnstr(test1, lookfor, len_short));
		printf("%s\n", strnstr(test0, "A", 0));
		printf("%s\n", strnstr(test0, "A", 1));
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
