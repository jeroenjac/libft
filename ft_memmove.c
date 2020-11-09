/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 17:52:01 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/09 21:34:54 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	tmp[len];
	unsigned int	i;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	i = 0;
	while (i < len)
	{
		tmp[i] = s[i];
		i++;
	}
	while (len > 0)
	{
		d[len - 1] = tmp[len - 1];
		len--;
	}
	return (dst);
}
