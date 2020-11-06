/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 19:03:13 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/06 16:41:21 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	d = dst;
	s = (unsigned char*)src;
	while (n > 0)
	{
		*d = *s;
		if (*s == c)
			return (d + 1);
		n--;
		d++;
		s++;
	}
	return (NULL);
}
