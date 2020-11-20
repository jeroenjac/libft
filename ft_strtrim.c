/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 07:27:59 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/20 13:20:17 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	size_t	n_before;
	size_t	n_after;
	size_t	len;
	size_t	len_trim;

	s = (char*)s1;
	n_before = 0;
	if (set == NULL)
		return (s);
	while(ft_strchr((char *)set, *(s + n_before)) != NULL)
		n_before++;
	len = ft_strlen(s);
	n_after = 0;
	while(ft_strchr((char *)set, *(s + len - n_after)) != NULL)
		n_after++;
	len_trim = len - n_before - n_after;
	return (ft_substr(s, n_before, len_trim + 1));
}
