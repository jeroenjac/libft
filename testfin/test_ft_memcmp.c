/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_memcmp.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 22:28:03 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/10 10:53:44 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		ft;
	size_t	len;
	int		res;

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
	
	//Test 0: Happy flow: normal input diff strings
	char	a0[] = "Codamm";
	char	b0[] = "KLMNOP";
	len = 6;
	if (ft == 1)
		res = ft_memcmp(a0, b0, len);
	else
		res = memcmp(a0, b0, len);
	printf("%i\n", res);

	//Test 1: len = 0;
	len = 0;
	if (ft == 1)
		res = ft_memcmp(a0, b0, len);
	else
		res = memcmp(a0, b0, len);
	printf("%i\n", res);

	//Test 2: a == b
	char	a2[] = "Codamm";
	char	b2[] = "Codamm";
	len = 60;
	if (ft == 1)
		res = ft_memcmp(a2, b2, len);
	else
		res = memcmp(a2, b2, len);
	printf("%i\n", res);
	
	//Test 3: a == b (only the n chars)
	char	a3[] = "Codammabc";
	char	b3[] = "Codammdef";
	len = 6;
	if (ft == 1)
		res = ft_memcmp(a3, b3, len);
	else
		res = memcmp(a3, b3, len);
	printf("%i\n", res);
	
	//Test 5: a has \0.
	char	a5[] = "Codam\0q";
	char	b5[] = "Codam\0\0";
	len = 7;
	if (ft == 1)
		res = ft_memcmp(a5, b5, len);
	else
		res = memcmp(a5, b5, len);
	printf("%i\n", res);
	
	//Test 6: using ints.
	int		int1  = 12;
	int		int2  = 18;
	int		*a6;
	int		*b6;
	a6 = &int1;
	b6 = &int2;
	len = 1;
	if (ft == 1)
		res = memcmp(a6, b6, len);
	else
		res = memcmp(a6, b6, len);
	printf("%i\n", res);

/*
	//Test 4: n = NULL;
	//Does not compile
	if (ft == 1)
		res = ft_memcmp(a3, b3, NULL);
	else
		res = memcmp(a3, b3, NULL);
	printf("%i\n", res);
*/
/*
	//Test 5: a = NULL;
	len = 3;
	if (ft == 1)
		res = ft_memcmp(NULL, b3, len);
	else
		res = memcmp(NULL, b3, len);
	printf("%i\n", res);
*/
}
