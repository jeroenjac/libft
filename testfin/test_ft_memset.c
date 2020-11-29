/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jjacobs <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 18:40:05 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/27 11:40:08 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "inittest.c"

int		inittest(int argc, char *ftname);

int		main(int argc, char **argv)
{
	int     ft;

    printf("prog: %s\n", argv[0]);
    ft = inittest(argc, "ft_memset");
	
	//For demo & Normal tests
	char	nulchar[1] = "0";
	
	//Some experimenting
	printf("What is sizeof(char)? It is %lu\n", sizeof(char));
	printf("What is sizeof(int)? It is %lu\n", sizeof(int));
	printf("What is sizeof(NULL)? It is %lu\n", sizeof(NULL));
	printf("What is sizeof('0')? It is %lu\n", sizeof('0'));
	printf("What is sizeof(\"0\")? It is %lu\n", sizeof("0"));
	printf("What is sizeof(char with value 0 / not terminated?)? It is %lu\n", sizeof(nulchar));
	printf("What is sizeof(\\0)? It is %lu\n", sizeof("\0"));

	
	//Section 1: Functional tets
	char	str0[60] = "yesyes";
	int		c;
	size_t	len;

	c = 'o';
	len = 50;	
	if (ft < 2)
		printf("Before: %s\n", str0);
	if (ft == 0)
		memset(str0, c, len);
	if (ft == 1)
		ft_memset(str0, c, len);
	if (ft < 2)
		printf("After: %s\n", str0);
	
	//Special case where last char of string is set to not \0,
	char	str1[6] = "hallo";
	
	c = 'k' + 256;
	len = 1;
	if (ft < 2)
		printf("Before: %s\n", str1);
	if (ft == 0)
		memset(str1 + 5, c, len);
	if (ft == 1)
		ft_memset(str1 + 5, c, len);
	if (ft < 2)
		printf("After: %s\n", str1);
	
	//Testing with cycling the possible char values
	char	str3[1000] = "haha";

	len = 20;
	c = ('j' - 257);

	if (ft < 2)
		printf("Before: %s\n", str3);
	if (ft == 0)
		memset(str3, c, len);
	if (ft == 1)
		ft_memset(str3, c, len);
	if (ft < 2)
		printf("After: %s\n", str3);
		
	//Testing with arrays of ints
	int		arr1[10];

	len = 2*sizeof(int);
	c = 2;	// 0b00000010 --> copy this byte onto all 4 bytes of int
			// int value becomes 2^1 + 2^9 + 2^17 + 2^25 = 3368018
	if (ft < 2)
		printf("Before memset(len = 2 * intsize), arr[3] = %d\n", arr1[3]);
	if (ft == 0)
		memset(arr1, c, len);
	if (ft == 1)
		ft_memset(arr1, c, len);
	if (ft < 2)
		printf("After memset(len = 2 * intsize), arr[3] = %d\n", arr1[3]);
	len = 3*sizeof(int) + 2; // Only x bytes of arr[3]
	if (ft < 2)
		printf("Before: %d\n", arr1[3]);
	if (ft == 0)
		memset(arr1, c, len);
	if (ft == 1)
		ft_memset(arr1, c, len);
	if (ft < 2)
		printf("After memset(len = %zu), arr[3] = %d\n", len, arr1[3]);
	len = 4*sizeof(int); // Full arr[3], see calc above.
	if (ft < 2)
		printf("Before memset(len = 4 * intsize), arr[3] = %d\n", arr1[3]);
	if (ft == 0)
		memset(arr1, c, len);
	if (ft == 1)
		ft_memset(arr1, c, len);
	if (ft < 2)
		printf("After memset(len = 4 * intsize), arr[3] = %d\n", arr1[3]);
	
	//Snowman printing, just for fun.
	printf("%c%c%c\n", 226, 152, 131);
}
