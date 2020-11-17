/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 18:31:52 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/17 10:05:15 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cr;
	int		len;

	len = ft_strlen(s);
	s = s + len;
	cr = (char)c;
	while (len > 0 && *s != cr)
	{
		len--;
		s--;
	}
	if (*s == cr)
		return ((char*)s);
	return (NULL);
}
