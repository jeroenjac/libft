/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inittest.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 08:32:49 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/27 09:34:21 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		inittest(int argc, char *ftname)
{
	int		ft;

	//More than 1 argument => No valid input
    //no arguments => work with libc function
    //1 argument => work with libft function
    ft = argc - 1;
    if (ft > 5)
        printf("Error w/ testing. Mode not supported\n");
    else
		printf("Testing/mode = %i: %s\n", ft, ftname);
    if (ft == 0)
        printf("TESTING LIBC FUNCTION\n");
    if (ft == 1)
        printf("TESTING LIBFT FUNCTION\n");
    if (ft == 2)
        printf("COMPARE TESTS LIBFT == LIBC (output diff not poss.)\n");
    if (ft == 3)
        printf("COMPARE TESTS LIBFT == Expected Output\n");
	if (ft == 4)
        printf("TEST LIBC - error result\n");
	if (ft == 5)
        printf("TEST LIBFT - error result\n");

	return (ft);
}
