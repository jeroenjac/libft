/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 15:59:31 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/12 18:27:07 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	res;
	int		minus;

	res = 0;
	minus = 1;
	if (*str == '-')
	{
		minus = -1;
		str++;
	}
	while (*str != '\0')
	{
		if (ft_isdigit(*str))
			res = res * 10 + *str - '0';
		else
			return (minus * (int)res);
		str++;
	}
	return (minus * (int)res);
}
