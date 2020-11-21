/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 16:46:57 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/21 15:49:23 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	digits(long nl)
{
	int		d;

	d = 0;
	if (nl == 0)
		return (1);
	if (nl < 0)
	{
		d++;
		nl = -nl;
	}
	while (nl > 0)
	{
		d++;
		nl = nl / 10;
	}
	return (d);
}

char		*ft_itoa(int n)
{
	long	nl;
	int		len;
	int		negative;
	char	*word;

	nl = n;
	len = digits(nl);
	negative = 0;
	word = (char*)malloc((len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	word[len] = '\0';
	if (nl < 0)
	{
		negative = 1;
		nl = -nl;
		word[0] = '-';
	}
	while (len > negative)
	{
		len--;
		word[len] = (nl % 10) + '0';
		nl = nl / 10;
	}
	return (word);
}
