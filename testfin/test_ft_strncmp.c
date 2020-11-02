/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strncmp.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 17:55:48 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/02 18:13:52 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "../libft.h"

int		main(void)
{
	char	str1[40] = "Hallo";
	char	str1b[40] = "oHallo";
	char	str0[10] = "";
	char	str99[1000] = "Hallo and very very long";

	printf("\nTesting ft_strncmp...\n");
	unsigned int	len = 3;
	printf("Test 1a: normal, compare %i chars < diff\n", len);
	printf("strncmp(%s, %s, %i) = %d\n", str1, str99, len, strncmp(str1, str99, len));
	printf("ft_strncmp(%s, %s, %i) = %d\n", str1, str99, len, ft_strncmp(str1, str99, len));
	
	write(1, "\n", 1);
	len = 7;
	printf("Test 1b: normal, compare %i chars > diff\n", len);
	printf("strncmp(%s, %s, %i) = %d\n", str1, str99, len, strncmp(str1, str99, len));
	printf("ft_strncmp(%s, %s, %i) = %d\n", str1, str99, len, ft_strncmp(str1, str99, len));
	
	write(1, "\n", 1);
	printf("Test 1c: normal, compare %i chars > diff. Flipped\n", len);
	printf("strncmp(%s, %s, %i) = %d\n", str99, str1, len, strncmp(str99, str1, len));
	printf("ft_strncmp(%s, %s, %i) = %d\n", str99, str1, len, ft_strncmp(str99, str1, len));
	
	write(1, "\n", 1);
	len = 0;
	printf("Test 2: normal, compare %i chars (zero)\n", len);
	printf("strncmp(%s, %s, %i) = %d\n", str1b, str99, len, strncmp(str1b, str99, len));
	printf("ft_strncmp(%s, %s, %i) = %d\n", str1b, str99, len, ft_strncmp(str1b, str99, len));
	
	write(1, "\n", 1);
	len = 2;
	printf("Test 3: one string is empty, compare %i chars\n", len);
	printf("strncmp(%s, %s, %i) = %d\n", str1, str0, len, strncmp(str1, str0, len));
	printf("ft_strncmp(%s, %s, %i) = %d\n", str1, str0, len, ft_strncmp(str1, str0, len));	
}
