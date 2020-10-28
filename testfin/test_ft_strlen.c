/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mstrlen.c                                          :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jjacobs <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 14:03:06 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/10/28 21:10:15 by jjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stddef.h>

#include "../libft.h"

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
}
