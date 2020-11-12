/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 22:32:45 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/12 22:46:58 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int c)
{
	unsigned int	p;

	p = (unsigned int)c;
	if (ft_isalpha(p) && p < 'a')
		p = p + 'a' - 'A';
	return (p);
}
