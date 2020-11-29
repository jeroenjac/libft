/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 21:52:55 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/29 18:15:00 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_toupper(int c)
{
	unsigned int	p;

	p = (unsigned int)c;
	if (ft_isalpha(p) && p > 'Z')
		p = p + 'A' - 'a';
	return (p);
}
