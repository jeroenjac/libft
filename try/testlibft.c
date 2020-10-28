/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testlibft.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jjacobs <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 14:03:06 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/10/27 18:12:31 by Jeroen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

//NEED TO DO: Include library, work with "ar"??
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memset(void *pt, int c, int len);

int		main(void)
{
	char	str1[40] = "Hallo";
	char	str0[10] = "";
	char	str99[1000] = "Hallo and very very long";

	printf("Testing ft_strlen...\n");
	printf("Test 1: normal");
	printf("strlen(%s) = %lu\n", str1, strlen(str1));
	printf("ft_strlen(%s) = %lu\n", str1, ft_strlen(str1));
	printf("Test 2: empty string\n");
	printf("strlen(%s) = %lu\n", str0, strlen(str0));
	printf("ft_strlen(%s) = %lu\n", str0, ft_strlen(str0));
	printf("Test 3: very long string (longer than int..?)\n");
	printf("strlen(%s) = %lu\n", str99, strlen(str99));
	printf("ft_strlen(%s) = %lu\n", str99, ft_strlen(str99));

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
	
	//To test the memset function
	char	str2[40] = "Hallo";
	char	c;

	c = 'q';
	len = 3;
	printf("\nComparing memset with ft_memset..\n");
	printf("i: %s. Set %i chars to %c.\n", str1, len, c);
	memset(str1, c, len);
	printf("o1: %s\n", str1);
	printf("i: %s. Set %i chars to %c.\n", str2, len, c);
	ft_memset(str2, c, len);
	printf("o2: %s\n", str2);

	//printf("Testing ft_strlcpy...\n");
	//printf("Test 1: ft_strlcpy(%s) = %d\n", str1, ft_strlcpy(str1));
	//printf("Test 2: ft_strlcpy(\"\") = %d\n", ft_strlcpy(""));
}
