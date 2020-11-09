/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 22:22:24 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/09 22:35:19 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	//Rules voor result bedenken - byte wise comp?
	
	while ((*s1 != '\0' || *s2 != '\0') && n-- > 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
	}
	return (0);
}
