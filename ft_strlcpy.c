/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 15:05:59 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/10 17:34:27 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t ldst)
{
	size_t	i;
	size_t	lens;

	lens = ft_strlen(src);
	i = 0;
	while (i + 1 < ldst && i < lens)
	{
		*dst = *src;
		i++;
		dst++;
		src++;
	}
	if (ldst > 0)
		*dst = '\0';
	return (lens);
}
