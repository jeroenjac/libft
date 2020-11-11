/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 18:31:52 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/11 18:43:58 by jjacobs       ########   odam.nl         */
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
	while (len > 0)
	{
		if (*s == cr)
			return ((char*)s);
		len--;
		s--;
	}
	return (NULL);
}
