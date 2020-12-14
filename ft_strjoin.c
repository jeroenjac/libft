/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 18:28:18 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/12/14 16:56:39 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*join;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = ft_calloc((len1 + len2 + 1), sizeof(char));
	if (join == NULL)
		return (NULL);
	ft_memcpy(join, (char*)s1, len1 * sizeof(char));
	ft_memcpy(join + len1, (char*)s2, len2 * sizeof(char));
	join[len1 + len2] = '\0';
	return (join);
}
