/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 13:02:30 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/13 13:12:29 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //for malloc
#include "libft.h" // for ft_bzero

void	*ft_calloc(size_t count, size_t size)
{
	int		*ptr;

	//malloc for count * size? is in bytes
	ptr = malloc(size * count);
	//bzero for these bytez
	ft_bzero(ptr, size * count);
	return (ptr);
}
