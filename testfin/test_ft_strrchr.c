/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strlcat.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 18:35:15 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/11 18:53:32 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>
#include <stdio.h>
#include <limits.h>

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
	char	s3[50] = "aaaaab1aab2aaaaaaaaaaaaaaab3";	
	char	c = 'b';
	char	nf = 'q';

	if (ft == 1)
	{
		printf("%s\n", ft_strrchr(s1, c));
		printf("%s\n", ft_strrchr(s2, c));
		printf("%s\n", ft_strrchr(s3, c));
		printf("%s\n", ft_strrchr(s2, nf));
		printf("%s\n", ft_strrchr(s2, '2'));
	}
	else
	{
		printf("%s\n", strrchr(s1, c));
		printf("%s\n", strrchr(s2, c));
		printf("%s\n", strrchr(s3, c));
		printf("%s\n", strrchr(s2, nf));
		printf("%s\n", strrchr(s2, '2'));
	}

	//Section 2: Tests with emtpy string
	char	e1[50] = "";
	if (ft == 1)
		printf("%s\n", ft_strrchr(e1, c));
	else
		printf("%s\n", strrchr(e1, c));
/*
	//Section 3: Tests with str = NULL
	//libc and libft seg fault
	if (ft == 1)
		printf("%s\n", ft_strrchr(NULL, c));
	else
		printf("%s\n", strrchr(NULL, c));
	
	//Section 4: Tests with c = NULL
	//Does not compile
	if (ft == 1)
		printf("%s\n", ft_strrchr(s1, NULL));
	else
		printf("%s\n", strrchr(s1, NULL));
*/
	
	//Section 5: Tests with various c
	char	swnp[50] = "aaabb~ddd";
	printf("int max = %i\n", INT_MAX);
	if (ft == 1)
	{
		printf("%s\n", ft_strrchr(swnp, 4)); // eot
		printf("%s\n", ft_strrchr(swnp, 126)); // ~
		printf("%s\n", ft_strrchr(swnp, 240)); // non ascii
		printf("%s\n", ft_strrchr(swnp, 1000000)); // cycling int?
		printf("%s\n", ft_strrchr(swnp, -42)); // negatives
		printf("%s\n", ft_strrchr(swnp, INT_MAX)); // int max
		printf("%s\n", ft_strrchr(swnp, INT_MIN));
		printf("%s\n", ft_strrchr(swnp, 'd'));
		printf("%s\n", ft_strrchr(swnp, 0));
		printf("%s\n", ft_strrchr(swnp, '\0'));
	}
	else
	{
		printf("%s\n", strrchr(swnp, 4));
		printf("%s\n", strrchr(swnp, '~'));
		printf("%s\n", strrchr(swnp, 240)); // non ascii
		printf("%s\n", strrchr(swnp, 1000000)); // cycling int? nvm
		printf("%s\n", strrchr(swnp, -42)); // negatives
		printf("%s\n", strrchr(swnp, INT_MAX));
		printf("%s\n", strrchr(swnp, INT_MIN));
		printf("%s\n", strrchr(swnp, 'd'));
		printf("%s\n", strrchr(swnp, 0));
		printf("%s\n", strrchr(swnp, '\0'));
	}
	
	//Section 6: c only after \0
    char s6[50] = "aaaaaaaabaaaababab";
    if (ft == 1)
        printf("%s\n", ft_strrchr(s6, 'b'));
    else
        printf("%s\n", strrchr(s6, 'b'));
    printf("%s\n", s6);
    s6[6] = '\0';
    printf("%s\n", s6);
    if (ft == 1)
        printf("%s\n", ft_strrchr(s6, 'b'));
    else
        printf("%s\n", strrchr(s6, 'b'));
}
