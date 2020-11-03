/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_memcpy.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 12:03:58 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/03 20:56:09 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	char	src[10] = "Wording";
	char	dst[10] = "Luke";
	char	sp[40];
	char	dp[40];
	char	sp1[] = "ReadWrite";
	char	dp1[] = "Correction";
	char	*sp2 = "Readonly";
	char	*dp2 = "Dist";
	int		ft;

	//More than 1 argument => No valid input
	//no arguments => work with libc function
	//1 argument => work with libft function
	if (argc > 2)
	{
		printf("Error w/ testing. Only use 0 or 1 arguments.\n");
		return (0);
	}
	else if (argc == 2)
		ft = 1;
	else
		ft = 0;
	
	//Test 1
	int		n = 5;
	printf("%s, %s\n", dst, src);
	if (ft == 1)
		ft_memcpy(dst, src, n);
	else
		memcpy(dst, src, n);
	printf("%s, %s\n", dst, src);

	//Test 2
	strcpy(sp, "AA-");
	strcpy(dp, "lololo");
	printf("%s, %s\n", dp, sp);
	if (ft == 1)
		ft_memcpy(dp, sp, 2);
	else
		memcpy(dp, sp, 2);
	printf("%s, %s\n", dp, sp);	

	//Test 3
	printf("%s, %s\n", dp1, sp1);
	if (ft == 1)
		ft_memcpy(dp1, sp1, 2);
	else
		memcpy(dp1, sp1, 2);
	printf("%s, %s\n", dp1, sp1);

	//Test 4: result is  bus error, not suitable for automation?
	printf("%s, %s\n", dp2, sp2);
	//if (ft == 1)
		//ft_memcpy(dp2, sp2, 2);
	//else
		//memcpy(dp2, sp2, 2);
	printf("%s, %s\n", dp2, sp2);

	//Test 5: add  src or dst being NULL pointers / pointers to NULL?
	return (0);
}
