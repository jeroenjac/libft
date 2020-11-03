/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 10:55:23 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/03 10:55:36 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_bzero(void *p0, size_t len)
{
	ft_memset(p0, 0, len);
	return (p0);
}
