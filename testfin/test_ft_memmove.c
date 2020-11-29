/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_memmove.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 14:07:31 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/29 23:15:15 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "inittest.c"

int		main(int argc, char **argv)
{
	int		ft;
    
	printf("prog: %s\n", argv[0]);
	ft = inittest(argc, "ft_memmove");

	size_t	len;	
	
	//Test0: Happy flow: normal input
	char	src0[] = "Codamm";
	char	dst0[] = "KLMNOP";
	char	*rp0;
	len = 4;
	if (ft == 1)
		rp0 = ft_memmove(dst0, src0, len);
	if (ft == 0)
		rp0 = memmove(dst0, src0, len);
	printf("%s\n", rp0);
	
	//Test1: len = 0
	char	src1[] = "Nulyes";
	char	dst1[] = "Where are we?";
	char	*rp1;
	len = 0;
	if (ft == 1)
		rp1 = ft_memmove(dst1, src1, len);
	if (ft == 0)
		rp1 = memmove(dst1, src1, len);
	printf("%s\n", rp1);
	
	//Test 2: len > src.
	//ASAN issue
	char	src2[30] = "Source";
	char	dst2[300] = "New testing strat";
	char	*rp2;
	len = 50;
	if (ft == 1)
		rp2 = ft_memmove(dst2, src2, len);
	if (ft == 0)
		rp2 = memmove(dst2, src2, len);
	printf("%s\n", rp2);

/*
	//Test 3: len > dst.
	//Libc aborts, not enough size. Libft works.
	char	src3[10] = "Source";
	char	dst3[30] = "New testing strat";
	char	*rp3;
	len = 300;
	if (ft == 1)
		rp3 = ft_memmove(dst3, src3, len);
	if (ft == 0)
		rp3 = memmove(dst3, src3, len);
	printf("%s\n", rp3);
*/
/*
	//Test 4: len < 0;
	// Libc abort, libft seg fault
	char	src4[30] = "Source";
	char	dst4[30] = "New testing strat";
	char	*rp4;
	len = -3;
	if (ft == 1)
		rp4 = ft_memmove(dst4, src4, len);
	if (ft == 0)
		rp4 = memmove(dst4, src4, len);
	printf("%s\n", rp4);
*/
/*
	//Test 5: len = NULL;;
	// Libc abort, libft seg fault
	char	src5[30] = "Source";
	char	dst5[30] = "New testing strat";
	char	*rp5;
	if (ft == 1)
		rp5 = ft_memmove(dst5, src5, NULL);
	if (ft == 0)
		rp5 = memmove(dst5, src5, NULL);
	printf("%s\n", rp5);
*/
/*
	//Test 6: src = NULL;;
	// Libc & libft seg fault
	char	dst6[30] = "New testing strat";
	char	*rp6;
	len = 5;
	if (ft == 1)
		rp6 = ft_memmove(dst6, NULL, len);
	if (ft == 0)
		rp6 = memmove(dst6, NULL, len);
	printf("%s\n", rp6);i
*/
/*	
	//Test 7: dst = NULL;
	// Libc & libft seg fault
	char	src7[30] = "New testing strat";
	char	*rp7;
	len = 5;
	if (ft == 1)
		rp7 = ft_memmove(NULL, src7, len);
	if (ft == 0)
		rp7 = memmove(NULL, src7,  len);
	printf("%s\n", rp7);
*/

	//Test 7b: both src and dst NULL
	char	*rp7b;
	char	*dst7b = (void *)0;		// = src
	
	len = 5;
	printf("Test with 2x NULL...\n");
	if (ft == 1)
		rp7b = ft_memmove(dst7b, dst7b, len);
	if (ft == 0)
		rp7b = memmove(dst7b, dst7b, len);
	printf("%s\n", rp7b);
	printf("...WORKS\n");
	
	//Test 77: testing with a very large int
	int size = 128 * 1024 * 1024;
	printf("Test for very large size of %i chars\n", size);
	char *d77 = (char *)malloc(sizeof(char) * size);
	char *s77 = (char *)malloc(sizeof(char) * size);
	char *rp77;
	
	if (ft == 1)
		rp77 = ft_memmove(d77, s77, size);
	if (ft == 0)
		rp77 = memmove(d77, s77, size);
	printf("%s\n", rp77);
	
	
	//Test 8: pointer to int.
	int		*src8;
	int		*dst8;
	int		ns = 4;
	int		nd = 256;
	src8 = &ns;
	dst8 = &nd;
	char	*rp8;
	len = 1;
	printf("%i\n", *dst8);
	if (ft == 1)
		rp8 = ft_memmove(dst8, src8, len);
	if (ft == 0)
		rp8 = memmove(dst8, src8,  len);
	printf("%i\n", *dst8);
	printf("%s\n", rp8);
}
