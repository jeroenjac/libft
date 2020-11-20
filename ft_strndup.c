/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strndup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 17:33:25 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/19 19:33:33 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h> //Remove

char	*ft_strndup(char *s1, size_t n)
{
	char	*dup;

	dup = malloc((n + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, s1, n * sizeof(char));
	*(dup + n) = '\0';
	return (dup);
}
