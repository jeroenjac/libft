/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_bzero.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 17:43:08 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/02 17:43:38 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

int		main(void)
{
	//Normal tests
	char	str10[6] = "yesyes";
	char	str20[6] = "yesyes";
	size_t	len;
	
	len = 4;

	printf("Before memset(): %s\n", str10);
	bzero(str10, len);
	printf("After memset(): %s\n", str10);
	printf("Before ft_memset(): %s\n", str20);
	ft_bzero(str20, len);
	printf("After ft_memset(): %s\n", str20);

/*
	//Special case where last char of string is set to not \0,
	char	str1[6] = "hallo";
	char	str2[6] = "hallo";
	
	c = 'k' + 256;
	len = 1;

	printf("Before memset(): %s\n", str1);
	memset(str1 + 5, len);
	printf("After memset(): %s\n", str1);
	printf("Before ft_memset(): %s\n", str2);
	ft_memset(str2 + 5, len);
	printf("After ft_memset(): %s\n (shows more random stuff, since terminating 0 is replaced by char)\n", str2);
	
	//Testing with cycling the possible char values
	char	str3[1000] = "haha";
	char	str4[1000] = "haha";

	len = 20;
	c = ('j' - 257 - 1000) % 256;

	printf("Before memset(): %s\n", str3);
	memset(str3, len);
	printf("After memset(): %s\n", str3);
	printf("Before ft_memset(): %s\n", str4);
	ft_memset(str4, len);
	printf("After ft_memset(): %s\n", str4);
*/	
	//Testing with arrays of ints
	int		arr1[10];
	int		arr2[10];
	int		i;

	i = -1;
	while (i++ < 9)
	{
		arr1[i] = i + 1;
		arr2[i] = arr1[i];
		//printf("i = %i\n", i);
	}

	len = 4*sizeof(int);
	
	printf("Before memset(), arr[3]: %d\n", arr1[3]);
	bzero(arr1, len);
	printf("After memset(), arr[3]: %d\n", arr1[3]);
	printf("Before ft_memset(), arr[3]: %d\n", arr2[3]);
	ft_bzero(arr2, len);
	printf("After ft_memset(), arr[3]: %d\n", arr2[3]);
	   
	return 0;
}

