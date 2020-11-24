/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strmapi.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 23:40:22 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/24 01:11:41 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>

/*
** Testing modes
** 0: Random proto
** 3: Compare some test functions against expected output
** 5: (and 4) invalid strmapi args
*/

#include "inittest.c"


//Test functions for strmapi
char	caps(unsigned int	index, char c);
char	c3(unsigned int	index, char c);
char	simple(unsigned int	index, char c);
char	toocomplex(unsigned int	index, char c, char c2);

int		main(int argc, char **argv)
{
	int		ft;

	printf("prog: %s\n", argv[0]);
	ft = inittest(argc, "ft_strmapi");

	//Random prototyping
	if (ft == 0)
	{
		char	*tr0;
	
		tr0 = ft_strmapi("some STRING", *caps);
		printf("%s\n", tr0);
		
		tr0 = ft_strmapi("codam all 42", *caps);
		printf("%s\n", tr0);
	}
	if (ft == 3)
	{
		int		comp;
	
		printf("Testing simple function not using int arg");
		comp = strcmp(ft_strmapi("codam12345", *simple), "1111100000");
		if (comp == 0)
			printf("\t\tSucces\n");
		
		printf("Testing function - should work on char 3");
		comp = strcmp(ft_strmapi("12345", *c3), "12C45");
		if (comp == 0)
			printf("\t\tSucces\n");

		printf("Testing function - should alternate cap & non-cap");
		comp = strcmp(ft_strmapi("codam all 42", *caps), "cOdAm aLl 42");
		if (comp == 0)
			printf("\tSucces\n");
	}
	//Wrong input to function, or invalid fun ptr - does compile but segfaults
	char	*tr5;

		if (ft == 4)
			tr5 = ft_strmapi(NULL, *c3);
		if (ft == 5)
			tr5 = ft_strmapi("Test", NULL);

		//Function wrong does not have expected number of args - can not compile
		/*
		char	*tr5;

		tr5 = ft_strmapi("KOEK VETO", *toosimple);
		printf("%s\n", tr5);
	
		tr5 = ft_strmapi("KOEK VETO", *toocomplex);
		printf("%s\n", tr5);
		*/
}


char	caps(unsigned int	index, char c)
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
	index = 0;	
	return (ft_isalpha(c) + '0');
}

char	toosimple(char c)
{
	return (ft_isalpha(c) + '0');
}

char	toocomplex(unsigned int	index, char c, char c2)
{
	if (index != 0)
		return (ft_isalpha(c) + '0');
	else
		return (ft_isalpha(c2) + '0');
}
