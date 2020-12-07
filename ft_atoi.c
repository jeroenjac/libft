/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 15:59:31 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/12/07 17:00:16 by jjacobs       ########   odam.nl         */
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
	unsigned long long	max;
	unsigned long long	res;
	int					minus;

	max = (long long)LONG_MAX;
	res = 0;
	minus = 1;
	while (isspace(*str) == 1)
		str++;
	if (*str == '-')
		minus = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		res *= 10;
		res += (int)(*str - '0');
		if (minus == -1 && res > max + 1)
			return (0);
		else if (minus == 1 && res > max)
			return (-1);
		str++;
	}
	return ((minus * res));
}
