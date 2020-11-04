/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_memcpy.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 12:03:58 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/04 19:26:12 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int		ft;
	size_t	n;

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
	
	//Test 0: Test with n = 0 bytes.
	char	src0[10] = "Zero";
	char	dst0[10] = "Full";
	printf("%s, %s\n", dst0, src0);
	if (ft == 1)
		ft_memcpy(dst0, src0, 0);
	else
		memcpy(dst0, src0, 0);
	printf("%s, %s\n", dst0, src0);
/*
	//Test -1: Test with n = -1; libc abort, libfr segfault; n (size_t) positive..
	char	srcneg[10] = "Yes";
	char	dstneg[10] = "Neg";
	n = -5;
	printf("%s, %s\n", dstneg, srcneg);
	if (ft == 1)
		ft_memcpy(dstneg, srcneg, n);
	else
		memcpy(dstneg, srcneg, n);
	printf("%s, %s\n", dstneg, srcneg);
*/	
	//Test 1: Normal test with n bytes.
	char	src1[10] = "Star";
	char	dst1[10] = "Luke";
	n = 5;
	printf("%s, %s\n", dst1, src1);
	if (ft == 1)
		ft_memcpy(dst1, src1, n);
	else
		memcpy(dst1, src1, n);
	printf("%s, %s\n", dst1, src1);

	//Test 2
	char	sp2[40];
	char	dp2[40];
	strcpy(sp2, "AABBCC");
	strcpy(dp2, "lololo");
	printf("%s, %s\n", dp2, sp2);
	if (ft == 1)
		ft_memcpy(dp2, sp2, 3);
	else
		memcpy(dp2, sp2, 3);
	printf("%s, %s\n", dp2, sp2);	

	//Test 3: Arrays for sp3/dp3 are reserved and R/W.
	char	sp3[] = "ReadWrite";
	char	dp3[] = "Correction";
	printf("%s, %s\n", dp3, sp3);
	if (ft == 1)
		ft_memcpy(dp3, sp3, 2);
	else
		memcpy(dp3, sp3, 2);
	printf("%s, %s\n", dp3, sp3);
/*
	//Test 4: bus error for libc and libft. Exit.
	char	*sp4 = "Readonly";
	char	*dp4 = "Dist";
	printf("%s, %s\n", dp4, sp4);
	if (ft == 1)
		ft_memcpy(dp4, sp4, 2);
	else
		memcpy(dp4, sp4, 2);
	printf("%s, %s\n", dp4, sp4);
*/
/*
	//Test 5: src = NULL (var). Libc function gives seg fault.
	char	src5[10];
	char	*src5p = NULL;
	char	dst5[10] = "Lala";
	char	*pt5;
	pt5 = src5;
	makenull(&pt5);
	printf("%s, %s\n", dst5, src5p);
	if (ft == 1)
		ft_memcpy(dst5, src5p, 2);
	else
		memcpy(dst5, src5p, 2);
	printf("%s, %s\n", dst5, src5p);
*/
/*
	//Test 5b: dst = NULL (direct). Libc functions gives seg fault. Libft proceeds.
	char	dst5b[10] = "oneone";
	printf("%s, %s\n", dst5b, NULL);
	if (ft == 1)
		ft_memcpy(dst5b, NULL, 2);
	else
		memcpy(dst5b, NULL, 2);
	printf("%s, %s\n", dst5b, NULL);
*/

	//Test 5c: works ok for libc and libft if (n <= nbytes + 1);
	char dss[] = "ABC";
	if (ft == 1)
		printf("New random test: %s\n", ft_memcpy(dss, "123", 2));
	else
		printf("New random test: %s\n", memcpy(dss, "123", 2));

/*
	//Test 6: dst = NULL (var). Libc functions gives seg fault. Libft proceeds.
	char	src6[10] = "Moon";
	char	*dst6 = NULL;
	printf("%s, %s\n", dst6, src6);
	if (ft == 1)
		ft_memcpy(dst6, src6, 2);
	else
		memcpy(dst6, src6, 2);
	printf("%s, %s\n", dst6, src6);
*/
/*
	//Test 6b: dst = NULL (direct). Libc functions gives seg fault. Libft proceeds.
	char	src6b[10] = "nulnul";
	printf("%s, %s\n", NULL, src6b);
	if (ft == 1)
		ft_memcpy(NULL, src6b, 2);
	else
		memcpy(NULL, src6b, 2);
	printf("%s, %s\n", NULL, src6b);
*/
/*
	//Test 6c: does not work for libft or libc. src is not R/W. 
	char sss[] = "DEF";
	if (ft == 1)
		printf("New random test2: %s\n", ft_memcpy("456", sss, 2));
	else
		printf("New random test2: %s\n", memcpy("456", sss, 2));
*/	
	
	//Test 7a: Test for int. Libc and Libft same.
	//For n >> int size (4), no compile error is given (as with char).
	//Reason: int is not direct input of memcpy, but via pointer?
	int		numd7 = 255;	// 1111-1111
	int		nums7 = 4;		// 0000-0100
	int		*npd;
	int		*nps;
	n = 1; //For now to be safe = 1. 
	printf("Int size = %zu\n", sizeof(int));
	npd = &numd7;
	nps = &nums7;
	printf("%i, %i\n", *npd, *nps);
	if (ft == 1)
		ft_memcpy(npd, nps, n);
	else
		memcpy(npd, nps, n);
	printf("%i, %i\n", *npd, *nps);	


	//Test 7b: Test for int of more than 1 byte. Libc and Libft same.
	//Re-using pointers from 7a.
	//With n = 1, only the value ~ byte 1 is replaced by src
	//With n > 1, also the number ( < 2^16 - 1)
	int		numd7b = 261;	// 0b: 1--0000-0000
	int		nums7b = 4;		// 0b: x--0000-0100

	npd = &numd7b;
	nps = &nums7b;
	n = 2;
	printf("%i, %i\n", *npd, *nps);
	if (ft == 1)
		ft_memcpy(npd, nps, n);
	else
		memcpy(npd, nps, n);
	printf("%i, %i\n", *npd, *nps);	

	
	//Test 7c: Test for int arrays. Libc and Libft same.
	//Byte wise behavior? To see sth changing in 2nd int n > 4
	int		numsrc7[5] = {234, 345, 456, 567, 678};
	int		numdst7[5] = {101, 102, 103, 104, 105};
	int		ct = 5;

	n = 10;
	while (ct-- > 0)
		printf("(%i, %i), ", numdst7[4 - ct], numsrc7[4 - ct]);
	printf("\n");
	if (ft == 1)
		ft_memcpy(numdst7, numsrc7, n);
	else
		memcpy(numdst7, numsrc7, n);
	ct = 5;
	while (ct-- > 0)
		printf("(%i, %i), ", numdst7[4 - ct], numsrc7[4 - ct]);
	printf("\n");
	
	//Test X: other data types?
	
	return (0);
}
