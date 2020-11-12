/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_atoi.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 16:11:45 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/12 20:55:49 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

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
	int		nt = 14;
	int		i;
	char	*tests[nt];
	tests[0] = "123";
	tests[1] = "2020202020203"; //atoi is bound by max int?
	tests[2] = "-42";
	tests[3] = "a-42"; //invalid char = 0?
	tests[4] = "--42"; //2x minus is invalid char?
	tests[5] = "1000a-42"; //takes the first valid chars
	tests[6] = "1000--42"; //takes the first valid chars
	tests[7] = "1000-42"; //takes the first valid chars
	tests[8] = ""; //does nothing.
	tests[9] = "007 00007";
	tests[10] = "!!\5"; // \is a special sign
	tests[11] = "!!''56"; // \is a special sign
	tests[12] = "a-42"; //invalid char = 0?
	tests[13] = "22!a-42"; //invalid char = 0?
	i = 0;
	while (i <= nt - 1)
	{	
		if (ft == 1)
			printf("%s = %i\n", tests[i], ft_atoi(tests[i]));
		else
			printf("%s = %i\n", tests[i], atoi(tests[i]));
		i++;
	}
	
	//Section 2: tests with int max/min
	char	num1[20];
	char	num2[20];
	char	num3[20] = "2147483648";
	char	num4[20] = "-2147483649";
	sprintf(num1, "%i", INT_MAX);
	sprintf(num2, "%i", INT_MIN);
	if (ft == 1)
	{
		printf("%s = %i\n", num1, ft_atoi(num1));
		printf("%s = %i\n", num2, ft_atoi(num2));
		printf("%s = %i\n", num3, ft_atoi(num3));
		printf("%s = %i\n", num4, ft_atoi(num4));
	}
	else
	{
		printf("%s = %i\n", num1, atoi(num1));
		printf("%s = %i\n", num2, atoi(num2));
		printf("%s = %i\n", num3, atoi(num3));
		printf("%s = %i\n", num4, atoi(num4));
	}
	
	//Section 3: special tests, fill in NULL etc.
	//libc & libft: seg fault
	if (ft == 1)
	{
		//printf("%s = %i\n", "nul", ft_atoi(NULL));
	}
	else
	{
		//printf("%s = %i\n", NULL, atoi(NULL));
	}
}
