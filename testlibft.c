/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testlibft.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 14:03:06 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/10/26 17:47:16 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

//NEED TO DO: Include library, work with "ar"??
int		ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, unsigned int n);

int		main(void)
{
	char	str1[40] = "Hallo";
	char	str0[10] = "";
	char	str99[1000] = "Hallo and very very long";

	printf("Testing ft_strlen...\n");
	printf("Test 1: normal");
	printf("strlen(%s) = %lu\n", str1, strlen(str1));
	printf("ft_strlen(%s) = %d\n", str1, ft_strlen(str1));
	printf("Test 2: empty string\n");
	printf("strlen(%s) = %lu\n", str0, strlen(str0));
	printf("ft_strlen(%s) = %d\n", str0, ft_strlen(str0));
	printf("Test 3: very long string (longer than int..?)\n");
	printf("strlen(%s) = %lu\n", str99, strlen(str99));
	printf("ft_strlen(%s) = %d\n", str99, ft_strlen(str99));

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
	printf("strncmp(%s, %s, %i) = %d\n", str1, str99, len, strncmp(str1, str99, len));
	printf("ft_strncmp(%s, %s, %i) = %d\n", str1, str99, len, ft_strncmp(str1, str99, len));
	
	write(1, "\n", 1);
	len = 2;
	printf("Test 3: one string is empty, compare %i chars\n", len);
	printf("strncmp(%s, %s, %i) = %d\n", str1, str0, len, strncmp(str1, str0, len));
	printf("ft_strncmp(%s, %s, %i) = %d\n", str1, str0, len, ft_strncmp(str1, str0, len));
	
	//printf("Testing ft_strlcpy...\n");
	//printf("Test 1: ft_strlcpy(%s) = %d\n", str1, ft_strlcpy(str1));
	//printf("Test 2: ft_strlcpy(\"\") = %d\n", ft_strlcpy(""));
}
