/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 16:46:57 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/20 18:08:53 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> //Remove
#include <limits.h> //Remove

/*
** APPROACH
** 0 check if input is valid; INT_MAX? Of oth behavior?
** 1 - determine size of number (base/power of 10) - FUNCTION
**		if 0 - return '0'. E.g. size is required.
**		if negative, size++, for the '-'.
** 2 - malloc size of string ~ size.
** 3 - for every n % base (~ size?), convert to char and put in string.
*/

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

char*		ft_itoa(int	n)
{
	int		len;
	long	nl;
	char	*word;

	nl = n;
	len = digits(nl) + 1;
	word = (char*)malloc(len * sizeof(char));
	printf("Size of word = %lu\n", sizeof(word));
	if (word == NULL)
		return (NULL);
	if (nl < 0)
	{
		*word = '-';
		nl = -nl;
	}
	word[len] = '\0';
	while (len > 1)
	{
		printf("Len = %i. Word = %s\n", len, word);
		word[len] = (char)((nl % 10) + '0');
		nl = nl / 10;
		len--;
	}
	//For testing digits function
	long i = -10;
	while (i < n)
	{
		printf("Digits %li = %i\n", i, digits(i));
		i++;
	}
	printf("Digits %i = %i\n", INT_MAX, digits(INT_MAX));
	printf("Digits %i = %i\n", INT_MIN, digits(INT_MIN));
	
	return(word);
}
