/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_memcmp.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 22:28:03 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/09 22:31:31 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		ft;
	size_t	len;
	int		res;

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
	
	//Test0: Happy flow: normal input
	char	src0[] = "Codamm";
	char	dst0[] = "KLMNOP";
	len = 4;
	if (ft == 1)
		res = ft_memcmp(dst0, src0, len);
	else
		res = memcmp(dst0, src0, len);
	printf("%i\n", res);
}
