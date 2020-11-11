/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strlcat.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 18:35:15 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/11 17:21:03 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		ft;

	//More than 1 argument => No valid input
    //no arguments => work with libc function
    //1 argument => work with libft function
    printf("prog: %s\n", argv[0]);
    if (argc > 2)
    {
        printf("Error w/ testing. Only use 0 or 1 arguments.\n");
        return (0);
    }
    else if (argc == 2)
        ft = 1;
    else
        ft = 0;
    if (ft == 1)
        printf("TESTING LIBFT FUNCTION\n");
    else
        printf("TESTING LIBC FUNCTION\n");

	//Section 1: Functional tests
	char	s1[50] = "aaaaabaaaaa";
	char	s2[50] = "aaaaab1aab2";	
	char	c = 'b';

	if (ft == 1)
	{
		printf("%s", ft_strchr(s1, c));
		printf("%s", ft_strchr(s2, c));
	}
	else
	{
		printf("%s", strchr(s1, c));
		printf("%s", strchr(s2, c));
	}
}
