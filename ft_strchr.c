/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 17:03:14 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/12/14 16:49:52 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	char	lookfor;

	lookfor = (char)c;
	while (*s != '\0' && *s != lookfor)
		s++;
	if (*s == lookfor)
		return ((char*)s);
	else
		return (NULL);
}

/*
** Casting c to char needed to work for INT_MIN
*/
