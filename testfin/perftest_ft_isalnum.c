/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   perftest_ft_isalnum.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 13:55:03 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/12 15:59:02 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include "../libft.h"
#include "limits.h"
#include <stdio.h>

int main(void)
{
	
	//Create while loop with many calls to function
	//Measure time using: time ./a.out

	// or option: return (ft_isalpha || ft_isdigit)
	// plus option: return (ft_isalpha + ft_isdigit)
	// if options: return (1/0) dep. on if statement
	// if advanced: check first isdigit, then isalpha.

	// With i = -1000000000;
	// ** isalnum (libc):				10,80 / 10,81 / 10.84 
	// ** isalnum (libft w. if):		14.21 / 14.36 / 14.27
	// ** isalnum (libft w. plus):		15.05 / 15.05 / 14.92
	// ** isalnum (libft w. or):		15.79 / 15.86 / 15.87
	// ** isalnum (libft w. adv if):	14.14 / 14.15 / 14.12

	//Record time

	int		i;
	long	j;
	int		max;
	int		res;

	i = -1e9;
	max = 1e9;

	j = 0;

	while (i <= max)
	{
		res = ft_isalnum(i);
		j++;
		i++;
	}
	printf("Done with %li cycles\n", j);
}
