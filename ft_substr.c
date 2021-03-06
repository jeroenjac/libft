/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 14:10:06 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/12/14 15:26:27 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s1, unsigned int start, size_t len)
{
	size_t	s1_left;

	if (s1 == NULL)
		return (NULL);
	s1_left = ft_strlen(s1);
	if (s1_left <= start)
		return (ft_strdup(""));
	s1_left = s1_left - start;
	if (s1_left < len)
		len = s1_left;
	return (ft_strndup((char *)s1 + start, len));
}
