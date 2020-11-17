/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strchr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 10:29:48 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/17 12:32:32 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include "inittest.c"

int		main(int argc, char **argv)
{
	int		ft;

    printf("prog: %s\n", argv[0]);
    ft = inittest(argc, "ft_strchr");

	//Section 1: Functional tests
	char	s1[50] = "aaaaabaaaaa";
	char	s2[50] = "aaaaab1aab2";
	char	s3[50] = "aaaaab1aab2aaaaaaaaaaaaaaab3";	
	char	s4[50] = "b0aaaab1aab2aaaaaaaaaaaaaaab3";	
	char	c = 'b';
	char	nf = 'q';

	if (ft == 1)
	{
		printf("%s\n", ft_strchr(s1, c));
		printf("%s\n", ft_strchr(s2, c));
		printf("%s\n", ft_strchr(s3, c));
		printf("%s\n", ft_strchr(s4, c));
		printf("%s\n", ft_strchr(s2, nf));
	}
	if (ft == 0)
	{
		printf("%s\n", strchr(s1, c));
		printf("%s\n", strchr(s2, c));
		printf("%s\n", strchr(s3, c));
		printf("%s\n", strchr(s4, c));
		printf("%s\n", strchr(s2, nf));
	}
	
	//Section 2: Tests with emtpy string
	char	e1[50] = "";
	if (ft == 1)
		printf("%s\n", ft_strchr(e1, c));
	if (ft == 0)
		printf("%s\n", strchr(e1, c));
/*
	//Section 3: Tests with str = NULL
	//libc and libft seg fault
	if (ft == 1)
		printf("%s\n", ft_strchr(NULL, c));
	else
		printf("%s\n", strchr(NULL, c));
	
	//Section 4: Tests with c = NULL
	//Does not compile
	if (ft == 1)
		printf("%s\n", ft_strchr(s1, NULL));
	else
		printf("%s\n", strchr(s1, NULL));
*/
	
	//Section 5: Tests with various c
	char	swnp[50] = "aaabb~ddd";
	if (ft < 2)
		printf("int max = %i\n", INT_MAX);
	if (ft == 1)
	{
		printf("%s\n", ft_strchr(swnp, 4)); // eot
		printf("%s\n", ft_strchr(swnp, 126)); // ~
		printf("%s\n", ft_strchr(swnp, 240)); // non ascii
		printf("%s\n", ft_strchr(swnp, 1000000)); // cycling int?
		printf("%s\n", ft_strchr(swnp, -42)); // negatives
		printf("%s\n", ft_strchr(swnp, INT_MAX)); // int max
		printf("%s\n", ft_strchr(swnp, INT_MIN));
		printf("%s\n", ft_strchr(swnp, 'd'));
		printf("%s\n", ft_strchr(swnp, 'a'));
		printf("%s\n", ft_strchr(swnp, 0));
		printf("Check for \\0\n");
		printf("%s\n", ft_strchr(swnp, '\0'));
		printf("%i\n", ft_strchr(swnp, '\0') == NULL);
	}
	if (ft == 0)
	{
		printf("%s\n", strchr(swnp, 4));
		printf("%s\n", strchr(swnp, '~'));
		printf("%s\n", strchr(swnp, 240)); // non ascii
		printf("%s\n", strchr(swnp, 1000000)); // cycling int? nvm
		printf("%s\n", strchr(swnp, -42)); // negatives
		printf("%s\n", strchr(swnp, INT_MAX));
		printf("%s\n", strchr(swnp, INT_MIN));
		printf("%s\n", strchr(swnp, 'd'));
		printf("%s\n", strchr(swnp, 'a'));
		printf("%s\n", strchr(swnp, 0));
		printf("Check for \\0\n");
		printf("%s\n", strchr(swnp, '\0'));
		printf("%i\n", strchr(swnp, '\0') == NULL);
	}
	
	//Section 5b: Compare tests
	if (ft == 2)
    {
        c = (char)INT_MIN;
        printf("c = INT MIN? \t");
        printf("%i\n", strchr("abc", c) == ft_strchr("abc", c));
        c = (char)INT_MAX;
        printf("c = INT MAX? \t");
        printf("%i\n", strchr("abc", c) == ft_strchr("abc", c));
        c = 0;
        printf("c = 0? \t\t");
        printf("%i\n", strchr("abc", c) == ft_strchr("abc", c));
        c = (char)NULL;;
        printf("c = NULL? \t");
        printf("%i\n", strchr("abc", c) == ft_strchr("abc", c));
    }

	//Section 6: c only after \0
	char s6[50] = "aaaaaaaabaaaababab";
	if (ft == 1)
		printf("%s\n", ft_strchr(s6, 'b'));
	if (ft == 0)
		printf("%s\n", strchr(s6, 'b'));
	if (ft < 2)
	{
		printf("%s\n", s6);
		s6[4] = '\0';
		printf("%s\n", s6);
	}
	if (ft == 1)
		printf("%s\n", ft_strchr(s6, 'b'));
	if (ft == 0)
		printf("%s\n", strchr(s6, 'b'));
}
