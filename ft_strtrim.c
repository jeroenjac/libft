/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 07:27:59 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/30 14:26:55 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <string.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	size_t	trimb;
	size_t	trime;
	size_t	len;
	size_t	len_trim;

	if (s1 == NULL)
		return (NULL);
	s = (char*)s1;
	trimb = 0;
	if (set == NULL)
		return (s);
	while (*(s + trimb) != '\0' && ft_strchr((char *)set, *(s + trimb)) != NULL)
		trimb++;
	len = ft_strlen(s);
	if (trimb == len)
		return ("");
	trime = 0;
	while (trime < len && ft_strchr((char *)set, *(s + len - trime)) != NULL)
		trime++;
	len_trim = len - trimb - trime;
	return (ft_substr(s, trimb, len_trim + 1));
}
