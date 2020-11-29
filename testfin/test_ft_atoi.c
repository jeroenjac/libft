/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_atoi.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 16:11:45 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/29 22:53:43 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "inittest.c"

int		main(int argc, char **argv)
{
	int		ft;

    printf("prog: %s\n", argv[0]);
	ft = inittest(argc, "ft_atoi");

	//Section 1: Functional tests
	int		nt = 20;
	int		i;
	char	*tests[nt];
	tests[0] = "123";
	tests[1] = "2020202020203"; //atoi is bound by max int?
	tests[2] = "-42";
	tests[3] = "a-42"; //invalid char = 0?
	tests[4] = "--42"; //2x minus is invalid char?
	tests[5] = "1000a-42"; //takes the first valid chars
	tests[6] = "2000--42"; //takes the first valid chars
	tests[7] = "1000-42"; //takes the first valid chars
	tests[8] = ""; //does nothing.
	tests[9] = "007 00007";
	tests[10] = "!!\5"; // \is a special sign
	tests[11] = "!!''56"; // \is a special sign
	tests[12] = "a-42"; //invalid char = 0?
	tests[13] = "22!a-42"; //invalid char = 0?
	tests[14] = "+2003"; //+ is valid/invalid?
	tests[15] = "++2020"; //2x + is valid/invalid?
	tests[16] = "+-303"; 
	tests[17] = "-+404"; 
	tests[18] = "-+-505"; 
	tests[19] = "\n-77"; //New line etc
	tests[19] = "\n\t\f\r\v     -77"; //New line etc
	i = 0;
	while (i <= nt - 1)
	{	
		if (ft == 1)
			printf("%s = %i\n", tests[i], ft_atoi(tests[i]));
		if (ft == 0)
			printf("%s = %i\n", tests[i], atoi(tests[i]));
		i++;
	}



/*
** 99999999999999999999999999 - test unittester
** 9223372036854775807444 - test jeroen
** 9223372036854775807 - long long int
*/

	//Section 2: tests with int max/min
	char	num1[20];
	char	num2[20];
	char	num3[20] = "2147483648";
	char	num4[20] = "-2147483649";
	char	num5[30] = "9223372036854775807444";
	sprintf(num1, "%i", INT_MAX);
	sprintf(num2, "%i", INT_MIN);
	if (ft == 1)
	{
		printf("%s = %i\n", num1, ft_atoi(num1));
		printf("%s = %i\n", num2, ft_atoi(num2));
		printf("%s = %i\n", num3, ft_atoi(num3));
		printf("%s = %i\n", num4, ft_atoi(num4));
		printf("Libft: over long int, different result\n");
		printf("%s = %i\n", num5, ft_atoi(num5));
	}
	if (ft == 0)
	{
		printf("%s = %i\n", num1, atoi(num1));
		printf("%s = %i\n", num2, atoi(num2));
		printf("%s = %i\n", num3, atoi(num3));
		printf("%s = %i\n", num4, atoi(num4));
		printf("Libc: over long int\n");
		printf("%s = %i\n", num5, atoi(num5));
	}
	
	//Section 3: special tests, fill in NULL etc.
	//libc & libft: seg fault
	if (ft == 1)
	{
		//printf("%s = %i\n", "nul", ft_atoi(NULL));
	}
	if (ft == 0)
	{
		//printf("%s = %i\n", NULL, atoi(NULL));
	}	
}
