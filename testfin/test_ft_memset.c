/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jjacobs <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 18:40:05 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/10/29 19:23:22 by jjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <string.h>

int		main(void)
{
	char	str1[6] = "hallo";
	char	str2[6] = "hallo";
	int		c;
	size_t	len;
	
	printf("What is sizeof(char)? It is %lu\n", sizeof(char));
	printf("What is sizeof(int)? It is %lu\n", sizeof(int));

	c = 'k';
	len = 1;

	printf("Before memset(): %s\n", str1);
	memset(str1 + 5, c, len);
	printf("After memset(): %s\n", str1);
	printf("Before ft_memset(): %s\n", str2);
	ft_memset(str2 + 5, c, len);
	printf("After ft_memset(): %s\n (shows more random stuff, since termining 0 is set to k by memset)\n", str2);
	
	char	str3[1000] = "haha";
	char	str4[1000] = "haha";

	len = 20;
	c = ('j' - 257 - 1000) % 256;
	
	printf("   %3d - %c\n", 129, 129);
	printf("Before memset(): %s\n", str3);
	memset(str3, c, len);
	printf("After memset(): %s\n", str3);
	printf("Before ft_memset(): %s\n", str4);
	ft_memset(str4, c, len);
	printf("After ft_memset(): %s\n", str4);
	
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
