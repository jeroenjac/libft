/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 18:33:10 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/30 22:36:28 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lens;
	size_t	lend;

	lens = ft_strlen(src);
	lend = ft_strlen(dst);
	if (dstsize <= lend)
		return (lens + dstsize);
	i = 0;
	while (i < lens && i < dstsize - lend - 1)
	{
		*(dst + lend + i) = *(src + i);
		i++;
	}
	*(dst + lend + i) = '\0';
	return (lens + lend);
}
