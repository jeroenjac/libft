/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strmapi.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 23:40:22 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/22 00:14:29 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** Testing modes
** 0: Random proto
*/

#include "inittest.c"

//Test functions for strmapi
char	capOdd(unsigned int	index, char c)
{
	if (index % 2 == 0)
		return (ft_tolower(c));
	else
		return(ft_toupper(c));
}

char	c3(unsigned int	index, char c)
{
	if (index == 2)
		return ('C');
	else
		return(c);
}

char	simple(unsigned int	index, char c)
{
	if (index != 2003)
		return (ft_isalpha(c) + '0');
	else
		return(c);
}

int		main(int argc, char **argv)
{
	int		ft;

	printf("prog: %s\n", argv[0]);
	ft = inittest(argc, "ft_strmapi");

	//Random prototyping

	char	*tr0;
	
	tr0 = ft_strmapi("some STRING", *capOdd);
	printf("%s\n", tr0);
	
	char	*tr1;
	
	tr1 = ft_strmapi("12345", *c3);
	printf("%s\n", tr1);
	
	tr1 = ft_strmapi("NRD", *c3);
	printf("%s\n", tr1);
	
	tr1 = ft_strmapi("KOEK VETO", *simple);
	printf("%s\n", tr1);
}
