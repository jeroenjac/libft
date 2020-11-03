/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jjacobs <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 18:40:05 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/03 16:34:55 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

int		main(void)
{
	//Normal tests
	char	str10[60] = "yesyes";
	char	str20[60] = "yesyes";
	int		c;
	size_t	len;
	char	nulchar[1] = "0";
	
	printf("What is sizeof(char)? It is %lu\n", sizeof(char));
	printf("What is sizeof(int)? It is %lu\n", sizeof(int));
	printf("What is sizeof(NULL)? It is %lu\n", sizeof(NULL));
	printf("What is sizeof('0')? It is %lu\n", sizeof('0'));
	printf("What is sizeof(\"0\")? It is %lu\n", sizeof("0"));
	printf("What is sizeof(char with value 0 / not terminated?)? It is %lu\n", sizeof(nulchar));
	printf("What is sizeof(\\0)? It is %lu\n", sizeof("\0"));

	c = 'k' - 256;
	len = 50;

	printf("Before memset(): %s\n", str10);
	memset(str10, c, len);
	printf("After memset(): %s\n", str10);
	printf("Before ft_memset(): %s\n", str20);
	ft_memset(str20, c, len);
	printf("After ft_memset(): %s\n (shows more random stuff, since terminating 0 is replaced by char)\n", str20);
	
	//Special case where last char of string is set to not \0,
	char	str1[6] = "hallo";
	char	str2[6] = "hallo";
	
	c = 'k' + 256;
	len = 1;

	printf("Before memset(): %s\n", str1);
	memset(str1 + 5, c, len);
	printf("After memset(): %s\n", str1);
	printf("Before ft_memset(): %s\n", str2);
	ft_memset(str2 + 5, c, len);
	printf("After ft_memset(): %s\n (shows more random stuff, since terminating 0 is replaced by char)\n", str2);
	
	//Testing with cycling the possible char values
	char	str3[1000] = "haha";
	char	str4[1000] = "haha";

	len = 20;
	c = ('j' - 257 - 1000) % 256;

	printf("Before memset(): %s\n", str3);
	memset(str3, c, len);
	printf("After memset(): %s\n", str3);
	printf("Before ft_memset(): %s\n", str4);
	ft_memset(str4, c, len);
	printf("After ft_memset(): %s\n", str4);
	
	//Testing with arrays of ints
	int		arr1[10];
	int		arr2[10];

	len = 2*sizeof(int);
	c = -1;
	
	printf("Before memset(), arr[3]: %d\n", arr1[3]);
	memset(arr1, c, len);
	printf("After memset(), arr[3]: %d\n", arr1[3]);
	printf("Before ft_memset(), arr[3]: %d\n", arr2[3]);
	ft_memset(arr2, c, len);
	printf("After ft_memset(), arr[3]: %d\n", arr2[3]);
	
	printf("%c%c%c\n", 226, 152, 131);
    return 0;
}
