/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 20:13:21 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/19 19:09:13 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	if (dst == NULL && src == NULL)
		return (dst);
	d = dst;
	s = src;
	while (n > 0)
	{
		*d = *s;
		n--;
		d++;
		s++;
	}
	return (dst);
}
