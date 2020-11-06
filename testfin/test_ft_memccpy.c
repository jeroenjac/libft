/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_memccpy.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 19:24:46 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/06 16:47:50 by jjacobs       ########   odam.nl         */
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
	int		c;

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
	c = 'r';
	n = 0;
	printf("%s, %s\n", dst0, src0);
	if (ft == 1)
		ft_memccpy(dst0, src0, c, n);
	else
		memccpy(dst0, src0, c, n);
	printf("%s, %s\n", dst0, src0);
	
	//Test 0b: Test with c = 0 / '\0' / NULL..
	char	src0b[10] = "bZero";
	char	dst0b[10] = "bFull";
	c = 0;
	n = 2;
	printf("%s, %s\n", dst0b, src0b);
	if (ft == 1)
		ft_memccpy(dst0b, src0b, c, n);
	else
		memccpy(dst0b, src0b, c, n);
	printf("%s, %s\n", dst0b, src0b);
/*
	//Test -1: Test with n = -1; libc abort, libfr segfault; n (size_t) positive..
	char	srcneg[10] = "Yes";
	char	dstneg[10] = "Neg";
	n = -5;
	printf("%s, %s\n", dstneg, srcneg);
	if (ft == 1)
		ft_memccpy(dstneg, srcneg, c, n);
	else
		memccpy(dstneg, srcneg, c, n);
	printf("%s, %s\n", dstneg, srcneg);
*/
	
	//Test 1a: Normal test with n bytes. Printing dst and return ptr.
	//c is not found in first n bytes of dst.
	char	src1[15] = "CodamAmsterdam";
	char	dst1[15] = "BroodGroningen";
	char	*pr1;
	n = 12;
	c = 'A';
	printf("%s, %s. n = %zu, c = %c.\n", dst1, src1, n, c);
	if (ft == 1)
		pr1 = ft_memccpy(dst1, src1, c, n);
	else
		pr1 = memccpy(dst1, src1, c, n);
	printf("dst_new: %s\n", dst1);
	printf("ptr_return: %s\n", pr1);
	
	//Test 1b: c is found in first n bytes of dst.
	char	dst1b[15] = "BroodGroningen";
	n = 8;
	c = 'A';
	printf("%s, %s. n = %zu, c = %c.\n", dst1, src1, n, c);
	if (ft == 1)
		pr1 = ft_memccpy(dst1b, src1, c, n);
	else
		pr1 = memccpy(dst1b, src1, c, n);
	printf("dst_new: %s\n", dst1);
	printf("ptr_return: %s\n", pr1);
	
	//Test 1b: c is not found in dst.
	char	dst1c[15] = "BroodGroningen";
	n = 8;
	c = 'Q';
	printf("%s, %s. n = %zu, c = %c.\n", dst1, src1, n, c);
	if (ft == 1)
		pr1 = ft_memccpy(dst1c, src1, c, n);
	else
		pr1 = memccpy(dst1c, src1, c, n);
	printf("dst_new: %s\n", dst1);
	printf("ptr_return: %s\n", pr1);
	
	//Test 2: altmethod of setting src and dst. byte n == c.
	char	dst2[40];
	char	src2[40];
	char	*pr2;
	strcpy(dst2, "AABBCC");
	strcpy(src2, "loocoo");
	n = 4;
	c = 'c';
	puts(dst2);
	puts(src2);
	if (ft == 1)
		pr2 = ft_memccpy(dst2, src2, c, n);
	else
		pr2 = memccpy(dst2, src2, c, n);
	puts(dst2);
	printf("ptr_return: %s\n", pr2);
	
	//Test 2b: altmethod of setting src and dst. byte n == last byte of dst == c.
	char	dst2b[7];
	char	src2b[7];
	char	*pr2b;
	strcpy(dst2b, "AABBCC");
	strcpy(src2b, "loocor");
	n = 6;
	c = 'r';
	puts(dst2b);
	puts(src2b);
	if (ft == 1)
		pr2b = ft_memccpy(dst2b, src2b, c, n);
	else
		pr2b = memccpy(dst2b, src2b, c, n);
	puts(dst2b);
	printf("ptr_return: %s\n", pr2b);

	//Test 3: alt method of setting src and dst
	//(Arrays for sp3/dp3 are reserved and R/W)
	char	sp3[] = "ReadWrite";
	char	dp3[] = "Correction";
	char	*pr3;
	n = 7;
	c = 'e';
	printf("%s, %s. n = %zu, c = %c.\n", dp3, sp3, n, c);
	if (ft == 1)
		pr3 = ft_memccpy(dp3, sp3, c, n);
	else
		pr3 = memccpy(dp3, sp3, c, n);
	printf("dst:%s, return pointer:%s\n", dp3, pr3);

/*
	//Test 5: src = NULL (var). 
	//Libc function gives seg fault. Libft also.
	char	*src5p = NULL;
	char	dst5[10] = "Lala";
	n = 3;
	c = 'q';
	printf("%s, %s\n", dst5, src5p);
	if (ft == 1)
		ft_memccpy(dst5, src5p, c, n);
	else
		memccpy(dst5, src5p, c, n);
	printf("%s, %s\n", dst5, src5p);
*/
/*
	//Test 5b: dst = NULL (direct)
	//Libc functions gives seg fault. Libft also.
	char	dst5b[10] = "oneone";
	n = 2;
	c = 'q';
	printf("%s, %s\n", dst5b, NULL);
	if (ft == 1)
		ft_memccpy(dst5b, NULL, c, n);
	else
		memccpy(dst5b, NULL, c, n);
	printf("%s, %s\n", dst5b, NULL);
*/

	//Test 5c: works ok for libc and libft if (n <= nbytes + 1);
	char dst5c[] = "ABCDEF";
	n = 4;
	c = '2';
	if (ft == 1)
		printf("New random test: %s\n", ft_memccpy(dst5c, "123456", c, n));
	else
		printf("New random test: %s\n", memccpy(dst5c, "123456", c, n));

/*
	//Test 6: dst = NULL (var).
	//Libc functions gives seg fault. Libft also..
	char	src6[10] = "Moona";
	char	*dst6 = NULL;
	n = 4;
	c = 'o';
	printf("%s, %s\n", dst6, src6);
	if (ft == 1)
		ft_memccpy(dst6, src6, c, n);
	else
		memccpy(dst6, src6, c, n);
	printf("%s, %s\n", dst6, src6);
*/
/*
	//Test 6b: dst = NULL (direct).
	//Libc functions gives seg fault. Libft proceeds.
	char	src6b[10] = "nulnul";
	n = 4;
	c = 'u';
	printf("%s, %s\n", NULL, src6b);
	if (ft == 1)
		ft_memccpy(NULL, src6b, c, n);
	else
		memccpy(NULL, src6b, c, n);
	printf("%s, %s\n", NULL, src6b);
*/
/*
	//Test 6c: does not work for libft or libc. dst is not R/W. 
	char src6c[] = "DEF";
	n = 3;
	c = 'F';
	printf("Start 6c\n");
	if (ft == 1)
		printf("New random test2: %s\n", ft_memccpy("456", src6c, c, n));
	else
		printf("New random test2: %s\n", memccpy("456", src6c, c, n));
*/	
	
	//Test 7a: Test for int. Libc and Libft same.
	//For n >> int size (4), no compile error is given (as with char).
	//Reason: int is not direct input of memccpy, but via pointer?
	int		numd7 = 255;	// 1111-1111
	int		nums7 = 4;		// 0000-0100
	int		*npd;
	int		*nps;
	c = 11;
	n = 1; //For now to be safe = 1. 
	printf("Int size = %zu\n", sizeof(int));
	npd = &numd7;
	nps = &nums7;
	printf("%i, %i\n", *npd, *nps);
	if (ft == 1)
		ft_memccpy(npd, nps, c, n);
	else
		memccpy(npd, nps, c, n);
	printf("%i, %i\n", *npd, *nps);	


	//Test 7b: Test for int of more than 1 byte. Libc and Libft same.
	//Re-using pointers from 7a.
	//With n = 1, only the value ~ byte 1 is replaced by src
	//With n > 1, also the number ( < 2^16 - 1)
	int		numd7b = 261;	// 0b: 1--0000-0000
	int		nums7b = 4;		// 0b: x--0000-0100

	npd = &numd7b;
	nps = &nums7b;
	c = '4';
	n = 1;
	printf("%i, %i\n", *npd, *nps);
	if (ft == 1)
		ft_memccpy(npd, nps, c, n);
	else
		memccpy(npd, nps, c, n);
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
		ft_memccpy(numdst7, numsrc7, c, n);
	else
		memccpy(numdst7, numsrc7, c, n);
	ct = 5;
	while (ct-- > 0)
		printf("(%i, %i), ", numdst7[4 - ct], numsrc7[4 - ct]);
	printf("\n");
	
	//Test X: other data types?

	return (0);
}
