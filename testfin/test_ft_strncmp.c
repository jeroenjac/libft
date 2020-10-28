/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jjacobs <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 14:03:06 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/10/28 22:38:33 by jjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "../libft.h"

//NEED TO DO: Include library, work with "ar"??
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memset(void *pt, int c, int len);

int		main(void)
{
	char	str1[40] = "Hallo";
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
	printf("strncmp(%s, %s, %i) = %d\n", str1, str99, len, strncmp(str1, str99, len));
	printf("ft_strncmp(%s, %s, %i) = %d\n", str1, str99, len, ft_strncmp(str1, str99, len));
	
	write(1, "\n", 1);
	len = 2;
	printf("Test 3: one string is empty, compare %i chars\n", len);
	printf("strncmp(%s, %s, %i) = %d\n", str1, str0, len, strncmp(str1, str0, len));
	printf("ft_strncmp(%s, %s, %i) = %d\n", str1, str0, len, ft_strncmp(str1, str0, len));	
}
