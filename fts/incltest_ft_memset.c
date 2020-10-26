/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 18:40:05 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/10/26 19:51:04 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *pt, int c, int len)
{
	unsigned char *p;

	p = pt;
	while (len > 0)
	{
		*p = c;
		len--;
		p++;
	}
	return (pt);
}

#include <stdio.h>
#include <string.h>

int		main(void)
{
	//To test the memset function
	char	str1[30] = "hallo";
	char	str2[30] = "hallo";
	char	str0[30];
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
