/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_memchr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 12:52:58 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/25 16:21:21 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>
#include <stdio.h>
#include "inittest.c"

int		main(int argc, char **argv)
{
	int		ft;
    printf("prog: %s\n", argv[0]);

	ft = inittest(argc, "ft_memchr");
	

	size_t	n;
	int		c;

	//Happy flow (e.g. correct input)
	//Test 0: c in src, and within n bytes
	char	src0[] = "Codam";
	n = 4;
	c = 'd';
	if (ft == 1)
		printf("%s\n", ft_memchr(src0, c, n));
	if (ft == 0)
		printf("%s\n", memchr(src0, c, n));
	
	//Test 1: c in src, not within n bytes
	char	src1[] = "Amsterdam";
	n = 3;
	c = 'r';
	if (ft == 1)
		printf("%s\n", ft_memchr(src1, c, n));
	if (ft == 0)
		printf("%s\n", memchr(src1, c, n));
	
	//Test 2: c not in src
	char	src2[] = "Codam";
	n = 4;
	c = 'q';
	if (ft == 1)
		printf("%s\n", ft_memchr(src2, c, n));
	if (ft == 0)
		printf("%s\n", memchr(src2, c, n));
	
	//Test 3: c not in src, n larger than src.
	char src3[] = "Codam";
	n = 10;
	c = 'q';
	if (ft == 1)
		printf("%s\n", ft_memchr(src3, c, n));
	if (ft == 0)
		printf("%s\n", memchr(src3, c, n));
	
	//Test 4: c in src, multiple times, n larger than src.
	char src4[] = "Codinging";
	n = 40;
	c = 'i';
	if (ft == 1)
		printf("%s\n", ft_memchr(src4, c, n));
	if (ft == 0)
		printf("%s\n", memchr(src4, c, n));	
	
	//Non happy flows
	//Test 5: negative n.
	char src5[] = "Codamam";
	n = (-6); //This still works; Likely n will cycle to a positive value?
	c = 'a';
	if (ft == 1)
		printf("%s\n", ft_memchr(src5, c, n));
	if (ft == 0)
		printf("%s\n", memchr(src5, c, n));	
	
	//Less happy flow
	//Test 11: with some strange chars
	char src11[] = "/|\x12\xff\x09\x42\2002\42|\\";
	n = 10; //This still works; Likely n will cycle to a positive value?
	c = '\200';
	if (ft == 1)
		printf("%s\n", ft_memchr(src11, c, n));
	if (ft == 0)
		printf("%s\n", memchr(src11, c, n));	

/*
	//Test 6: n is NULL / "b" >> compile errors.
	char src6[] = "Lala6";
	n = NULL;
	c = 'a';
	if (ft == 1)
		printf("%s\n", ft_memchr(src6, c, n));
	if (ft == 0)
		printf("%s\n", memchr(src6, c, n));	
*/
/*
	//Test 7: use NULL as function input >> seg fault
	//char src7 = NULL;
	n = 10;
	c = 'n';
	if (ft == 1)
		printf("%s\n", ft_memchr(NULL, c, n));
	if (ft == 0)
		printf("%s\n", memchr(NULL, c, n));	
*/
/*
	//Test 8: trying with NULL as c..
	char src8[] = "Codinging";
	n = 40;
	//c = NULL;
	if (ft == 1)
		printf("%s\n", ft_memchr(src8, NULL, n));
	if (ft == 0)
		printf("%s\n", memchr(src8, NULL, n));	
*/
/*
	//Test 9: trying with NULL as n. >> compile error (test script), direct and via var.
	char src9[] = "Codinging";
	//n = NULL;
	c = 'd';
	if (ft == 1)
		printf("%s\n", ft_memchr(src9, c, NULL));
	if (ft == 0)
		printf("%s\n", memchr(src9, c, NULL));	
*/
}
