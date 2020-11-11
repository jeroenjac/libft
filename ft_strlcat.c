/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 18:33:10 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/11 15:07:13 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	lens;
	size_t	lend;

	lens = ft_strlen(src);
	lend = ft_strlen(dst);
	if (dsize < lend + 1)
		return (lens + dsize);
	i = 0;
	while (i < lens && i < dsize - lend - 1)
	{
		*(dst + lend + i) = *(src + i);
		i++;
	}
	*(dst + lend + i) = '\0';
	return (lens + lend);
}
