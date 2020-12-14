/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 10:08:23 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/12/14 15:25:56 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *nd, size_t len_s)
{
	size_t	len_nd;

	len_nd = ft_strlen(nd);
	if (*nd == '\0')
		return ((char*)hs);
	while (*hs != '\0' && len_s > 0)
	{
		if (len_s < len_nd)
			return (NULL);
		if (ft_strncmp(hs, nd, len_nd) == 0)
			return ((char*)hs);
		hs++;
		len_s--;
	}
	return (NULL);
}
