/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_calloc.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 13:24:39 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/13 13:28:55 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "inittest.c"

#include <stdlib.h>
#include "../libft.h"

int     inittest(int argc, char *ftname);

int     main(int argc, char **argv)
{
    int     ft;

    printf("prog: %s\n", argv[0]);
    ft = inittest(argc, "ft_calloc");

    //Section 1: Simple test: reserve for 10 * int?
	size_t		c1;
	size_t		s1;
	int			*resptr;

	c1 = 20;
	s1 = 8; //int size
	if (ft == 0)
		resptr = calloc(c1, s1);
	if (ft == 1)
		resptr = ft_calloc(c1, s1);
	printf("Size of result: %zu\n", sizeof(*resptr));
	
	//Free the pointers?

}

