/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jjacobs <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 18:40:05 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/10/27 16:59:20 by Jeroen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *p0, int c, size_t len)
{
	unsigned char *p;

	p = p0;
	while (len > 0)
	{
		*p = c;
		len--;
		p++;
	}
	return (p0);
}
