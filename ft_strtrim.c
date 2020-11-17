/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 07:27:59 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/17 12:52:49 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		nonset;
	int		trim_b;
	int		trim_e;

	if (s1 == NULL)
		return (0);
	if (set == NULL)
		return (ft_strdup(s1));
	nonset = 0;
	trim_b = 0;
	trim_e = ft_strlen(s1);
	while (nonset == 0)
	{
		if (ft_strchr(set, (int)*(s1 + trim_b)) == NULL)
			nonset = 1;
		trim_b++;
	}
	nonset = 0;
	while (trim_e > 0 && nonset == 0)
	{
		if (ft_strchr(set, (int)*(s1 + trim_e)) == NULL)
			nonset = 1;
		trim_e--;
	}
	return (ft_substr(s1, trim_b - 1, trim_e - trim_b + 3));
}
