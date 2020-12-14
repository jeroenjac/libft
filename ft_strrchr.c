/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 18:31:52 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/12/14 16:52:35 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	lookfor;
	int		len;

	len = ft_strlen(s);
	s = s + len;
	lookfor = (char)c;
	while (len > 0 && *s != lookfor)
	{
		len--;
		s--;
	}
	if (*s == lookfor)
		return ((char *)s);
	return (NULL);
}
