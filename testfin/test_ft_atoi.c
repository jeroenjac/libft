/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_atoi.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 16:11:45 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/12/07 16:50:13 by jjacobs       ########   odam.nl         */
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
	int		nt = 22;
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
	tests[20] = "-085";
	tests[21] = "\t\v\f\r\n \f-06050";

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
	printf("Tests for int max/min\n");
	char	num1[20];
	char	num2[20];
	char	num3[20] = "2147483648";
	char	num4[20] = "-2147483649";
	char	numl0[30] = "9223372036854775807440";
	char	numl1[30] = "9223372036854775807441";
	char	numl2[30] = "9223372036854775807442";
	char	numl3[30] = "9223372036854775807443";
	char	numl4[30] = "9223372036854775807444";
	char	numl5[30] = "9223372036854775807445";
	char	numl6[30] = "9223372036854775807446";
	char	numl7[30] = "9223372036854775807447";
	char	numl8[30] = "9223372036854775807448";
	char	numl9[30] = "9223372036854775807449";
	sprintf(num1, "%i", INT_MAX);
	sprintf(num2, "%i", INT_MIN);
	if (ft == 1)
	{
		printf("%s = %i\n", num1, ft_atoi(num1));
		printf("%s = %i\n", num2, ft_atoi(num2));
		printf("%s = %i\n", num3, ft_atoi(num3));
		printf("%s = %i\n", num4, ft_atoi(num4));
//	printf("Libft: over long int, different result\n");
		printf("%s = %i\n", numl0, ft_atoi(numl0));
		printf("%s = %i\n", numl1, ft_atoi(numl1));
		printf("%s = %i\n", numl2, ft_atoi(numl2));
		printf("%s = %i\n", numl3, ft_atoi(numl3));
		printf("%s = %i\n", numl4, ft_atoi(numl4));
		printf("%s = %i\n", numl5, ft_atoi(numl5));
		printf("%s = %i\n", numl6, ft_atoi(numl6));
		printf("%s = %i\n", numl7, ft_atoi(numl7));
		printf("%s = %i\n", numl8, ft_atoi(numl8));
		printf("%s = %i\n", numl9, ft_atoi(numl9));
	}
	if (ft == 0)
	{
		printf("%s = %i\n", num1, atoi(num1));
		printf("%s = %i\n", num2, atoi(num2));
		printf("%s = %i\n", num3, atoi(num3));
		printf("%s = %i\n", num4, atoi(num4));
//		printf("Libc: over long int\n");
		printf("%s = %i\n", numl0, atoi(numl0));
		printf("%s = %i\n", numl1, atoi(numl1));
		printf("%s = %i\n", numl2, atoi(numl2));
		printf("%s = %i\n", numl3, atoi(numl3));
		printf("%s = %i\n", numl4, atoi(numl4));
		printf("%s = %i\n", numl5, atoi(numl5));
		printf("%s = %i\n", numl6, atoi(numl6));
		printf("%s = %i\n", numl7, atoi(numl7));
		printf("%s = %i\n", numl8, atoi(numl8));
		printf("%s = %i\n", numl9, atoi(numl9));
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
