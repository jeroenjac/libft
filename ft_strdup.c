/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 20:55:38 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/19 19:17:42 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*dup;

	size = ft_strlen(s1) + 1;
	dup = malloc((size + 1) * sizeof(char));
	if (dup != NULL)
		ft_memcpy(dup, (char*)s1, size * sizeof(char));
	return (dup);
}
