/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 15:59:31 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/12/07 10:43:13 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	isspace(char ch)
{
	if (ch == '\t' || ch == '\n' || ch == '\v' ||\
		ch == '\f' || ch == '\r' || ch == ' ')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	long	res;
	int		minus;

	res = 0;
	minus = -1;
	while (isspace(*str) == 1)
		str++;
	if (*str == '-')
		minus = 1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		res *= 10;
		if (res < INT_MIN && minus == 1)
			return (0);
		else if (-res > INT_MAX && minus == -1)
			return (-1);
		res -= (long)(*str - '0');
		str++;
	}
	return (minus * res);
}
