/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strrchr.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 10:25:03 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/17 10:34:09 by jjacobs       ########   odam.nl         */
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
	ft = inittest(argc, "ft_strRchr");

	//Section 1: Functional tests
	char	s1[50] = "aaaaabaaaaa";
	char	s2[50] = "aaaaab1aab2";
	char	s3[50] = "aaaaab1aab2aaaaaaaaaaaaaaab3";	
	char	s4[50] = "aaaaab1aab2aaaaaaaaaaaaaaab";	
	char	s5[50] = "baaaaa";	
	char	c = 'b';
	char	nf = 'q';

	if (ft == 1)
	{
		printf("%s\n", ft_strrchr(s1, c));
		printf("%s\n", ft_strrchr(s2, c));
		printf("%s\n", ft_strrchr(s3, c));
		printf("%s\n", ft_strrchr(s4, c));
		printf("%s\n", ft_strrchr(s5, c));
		printf("%s\n", ft_strrchr(s2, nf));
		printf("%s\n", ft_strrchr(s2, '2'));
	}
	if (ft == 0)
	{
		printf("%s\n", strrchr(s1, c));
		printf("%s\n", strrchr(s2, c));
		printf("%s\n", strrchr(s3, c));
		printf("%s\n", strrchr(s4, c));
		printf("%s\n", strrchr(s5, c));
		printf("%s\n", strrchr(s2, nf));
		printf("%s\n", strrchr(s2, '2'));
	}

	//Section 2: Tests with emtpy string
	char	e1[50] = "";
	if (ft == 1)
		printf("%s\n", ft_strrchr(e1, c));
	if (ft == 0)
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
	if (ft < 2)
		printf("int max = %i\n", INT_MAX);
	if (ft == 1)
	{
		printf("%s\n", ft_strrchr(swnp, 4)); // eot
		printf("%s\n", ft_strrchr(swnp, 126)); // ~
		printf("%s\n", ft_strrchr(swnp, 240)); // non ascii
		printf("%s\n", ft_strrchr(swnp, 1000000)); // cycling int?
		printf("%s\n", ft_strrchr(swnp, -42)); // negatives
		printf("%s\n", ft_strrchr(swnp, INT_MAX)); // int max
		printf("%s\n", ft_strrchr(swnp, 'd'));
		printf("%s\n", ft_strrchr(swnp, 0));
		printf("%s\n", ft_strrchr(swnp, '\0'));
	}
	if (ft == 0)
	{
		printf("%s\n", strrchr(swnp, 4));
		printf("%s\n", strrchr(swnp, '~'));
		printf("%s\n", strrchr(swnp, 240)); // non ascii
		printf("%s\n", strrchr(swnp, 1000000)); // cycling int? nvm
		printf("%s\n", strrchr(swnp, -42)); // negatives
		printf("%s\n", strrchr(swnp, INT_MAX));
		printf("%s\n", strrchr(swnp, 'd'));
		printf("%s\n", strrchr(swnp, 0));
		printf("%s\n", strrchr(swnp, '\0'));
	}
	
	//Section 5b: Compare tests
	if (ft == 2)
	{
		c = (char)INT_MIN;
		printf("c = INT MIN? \t");
		printf("%i\n", strrchr("abc", c) == ft_strrchr("abc", c));
		c = (char)INT_MAX;
		printf("c = INT MAX? \t");
		printf("%i\n", strrchr("abc", c) == ft_strrchr("abc", c));
		c = 0;
		printf("c = 0? \t\t");
		printf("%i\n", strrchr("abc", c) == ft_strrchr("abc", c));
		c = (char)NULL;;
		printf("c = NULL? \t");
		printf("%i\n", strrchr("abc", c) == ft_strrchr("abc", c));
	}
	
	//Section 6: c only after \0
    char s6[50] = "aaaaaaaabaaaababab";
    if (ft == 1)
        printf("%s\n", ft_strrchr(s6, 'b'));
	if (ft == 0)
        printf("%s\n", strrchr(s6, 'b'));
    if (ft < 2)
	{
		printf("%s\n", s6);
		s6[6] = '\0';
		printf("%s\n", s6);
	}
    if (ft == 1)
        printf("%s\n", ft_strrchr(s6, 'b'));
	if (ft == 0)
        printf("%s\n", strrchr(s6, 'b'));
}
