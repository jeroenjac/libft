/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strlen.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 23:43:25 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/27 11:45:56 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "inittest.c"

#include <string.h>
#include <stddef.h>
#include "../libft.h"

int		main(int argc, char **argv)
{
	int		ft;
	
	printf("prog: %s\n", argv[0]);
	ft = inittest(argc, "ft_strlen");
	
	char	str1[40] = "Hallo";
	char	str0[10] = "";
	char	str99[1000] = "Hallo and very very long";

	//t1 - some simple tests
	if (ft == 0)
	{
		printf("Test 1: normal");
		printf("strlen(%s) = %lu\n", str1, strlen(str1));
		printf("Test 2: empty string\n");
		printf("strlen(%s) = %lu\n", str0, strlen(str0));
		printf("Test 3: very long string (longer than int..?)\n");
		printf("strlen(%s) = %lu\n", str99, strlen(str99));
	}
	if (ft == 1)
	{	
		printf("Test 1: normal");
		printf("strlen(%s) = %lu\n", str1, ft_strlen(str1));
		printf("Test 2: empty string\n");
		printf("strlen(%s) = %lu\n", str0, ft_strlen(str0));
		printf("Test 3: very long string (longer than int..?)\n");
		printf("strlen(%s) = %lu\n", str99, ft_strlen(str99));
	}

	//t2 - test on string that is not terminated;
	char	str2[14] = "Hello12345abc";
	str2[13] = 'd';
	
	if (ft == 0)
	{
		printf("Input: %s\n", str2);
		printf("Len =  %lu\n", strlen(str2));
	}
	if (ft == 1)
	{
		printf("Input: %s\n", str2);
		printf("Len =  %lu\n", ft_strlen(str2));
	}
	
	//t3 - test on NULL;
	// libc & libft segfaulting
	if (ft == 4)
		printf("Len =  %lu\n", strlen(NULL));
	if (ft == 5)
		printf("Len =  %lu\n", ft_strlen(NULL));
}
