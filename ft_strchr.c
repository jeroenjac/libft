/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 17:03:14 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/11 18:37:27 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	char	cr;

	cr = (char)c;
	while (*s != '\0')
	{
		s++;
		if (*s == cr)
			return ((char*)s);
	}
	return (NULL);
}