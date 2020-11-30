/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strndup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 17:33:25 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/30 14:56:39 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(char *s1, size_t n)
{
	char	*dup;

	dup = ft_calloc(n + 1, sizeof(char));
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, s1, n * sizeof(char));
	*(dup + n) = '\0';
	return (dup);
}
