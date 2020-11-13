/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inittest.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 08:32:49 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/13 09:02:44 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		inittest(int argc, char *ftname)
{
	int		ft;

	//More than 1 argument => No valid input
    //no arguments => work with libc function
    //1 argument => work with libft function
    if (argc > 3)
    {
        printf("Error w/ testing. Only use 0, 1 or 2 arguments.\n");
        return (0);
    }
    ft = argc - 1;
    printf("Testing/mode = %i: %s\n", ft, ftname);
    if (ft == 0)
        printf("TESTING LIBC FUNCTION\n");
    if (ft == 1)
        printf("TESTING LIBFT FUNCTION\n");
    if (ft == 2)
        printf("COMPARE TESTS LIBC == LIBFT (diff not poss.)\n");
	
	return (ft);
}
