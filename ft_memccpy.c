/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 19:03:13 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/04 19:34:40 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	if (dst == NULL || src == NULL)
		return (NULL);
	d = dst;
	s = src;
	while (n > 0 && c != 'z')
	{
		*d = *s;
		n--;
		d++;
		s++;
	}
	return (dst);
}
