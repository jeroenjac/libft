/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 15:05:59 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/26 13:56:51 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t ldst)
{
	size_t	i;
	size_t	lens;

	if (dst == NULL)
		return (0);
	lens = ft_strlen(src);
	i = 0;
	if (ldst != 0)
	{
		while (i < (ldst - 1) && *src != '\0')
		{
			*dst = *src;
			i++;
			dst++;
			src++;
		}
		*dst = '\0';
	}
	return (lens);
}
