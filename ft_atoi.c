/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 15:59:31 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/26 15:06:31 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	int	res;
	int	minus;

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
		res -= (int)(*str - '0');
		str++;
	}
	return (minus * res);
}
