/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 17:52:01 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/25 16:26:13 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dst == src)
		return (dst);
	if (src > dst)
		return (ft_memcpy(dst, (void *)src, len));
	d = dst + len - 1;
	s = (void *)src + len - 1;
	while (len > 0)
	{
		*d = *s;
		d--;
		s--;
		len--;
	}
	return (dst);
}
