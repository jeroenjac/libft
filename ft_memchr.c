/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 12:21:57 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/09 12:28:29 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char *s;

	s = (unsigned char*)src;
	while (n > 0)
	{
		if (*s == c)
			return (s);
		n--;
		s++;
	}
	return (NULL);
}
