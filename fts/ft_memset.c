/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 18:40:05 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/10/26 19:57:44 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *pt, int c, int len)
{
	unsigned char *p;

	p = pt;
	while (len > 0)
	{
		*p = c;
		len--;
		p++;
	}
	return (pt);
}
