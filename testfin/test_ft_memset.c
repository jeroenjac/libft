/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jjacobs <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 18:40:05 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/10/28 22:41:34 by jjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <string.h>

int		main(void)
{
	char	str1[30] = "hallo";
	char	str2[30] = "hallo";
	char	c;
	int		len;

	c = 'q';
	len = 2;

	printf("Before memset, str: %s\n", str1);
	memset(str1, c, len);
	printf("After memset, str: %s\n", str1);
	printf("Before memset, str: %s\n", str2);
	memset(str2, c, len);
	printf("After memset, str: %s\n", str2);
}
