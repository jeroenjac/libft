/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 17:52:08 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/13 11:23:40 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *p0, int c, size_t len)
{
	unsigned char *p;

	p = (unsigned char*)p0;
	while (len > 0)
	{
		*p = c;
		len--;
		p++;
	}
	return (p0);
}
