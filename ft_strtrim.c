/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 07:27:59 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/12/14 16:41:15 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	if (set == NULL)
		return (s);
	len = ft_strlen(s);
	trimb = 0;
	while (trimb < len && ft_strchr((char *)set, *(s + trimb)) != NULL)
		trimb++;
	if (trimb == len)
		return (ft_strdup(""));
	trime = 0;
	while (trime < len && ft_strchr((char *)set, *(s + len - trime)) != NULL)
		trime++;
	len_trim = len - trimb - (trime - 1);
	return (ft_substr(s, trimb, len_trim));
}
