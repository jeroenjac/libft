/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strlcat.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 18:35:15 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/11 17:12:59 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		ft;
	size_t	len;
	size_t	res;

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
	
	//Test 0: Testing with normal dst & src
	//Buffer large enough, len_total = 29 + \0
	//Test different len = 0
	char	src0[50] = "1234567890123456789"; // len = 19
	char	dst0[50] = "0----ABCDE"; //len = 10
	len = 0;
	printf("%s\n", dst0);
	printf("%s\n", src0);
	if (ft == 1)
		res = ft_strlcat(dst0, src0, len);
	else
		res = strlcat(dst0, src0, len);
	printf("%s\n", dst0);
	printf("%zu\n", res);
	
	//Test 1: Testing with normal dst & src
	//Buffer large enough, len_total = 29 + \0
	//Test different len = 12 < lend.
	char	dst1[50] = "1----ABCDE"; //len = 10
	len = 10;
	printf("%s\n", dst1);
	printf("%s\n", src0);
	if (ft == 1)
		res = ft_strlcat(dst1, src0, len);
	else
		res = strlcat(dst1, src0, len);
	printf("%s\n", dst1);
	printf("%zu\n", res);
	
	//Test 2: Testing with normal dst & src
	//Buffer large enough, len_total = 29 + \0
	//Test different len = 12 > lend.
	char	dst2[50] = "2----ABCDE"; //len = 10
	len = 12;
	printf("%s\n", dst2);
	printf("%s\n", src0);
	if (ft == 1)
		res = ft_strlcat(dst2, src0, len);
	else
		res = strlcat(dst2, src0, len);
	printf("%s\n", dst2);
	printf("%zu\n", res);
	
	//Test 3: Testing with normal dst & src
	//Buffer large enough, len_total = 29 + \0
	//Test different len = 40 > lend + lens.
	char	dst3[50] = "3----ABCDE"; //len = 10
	len = 29;
	printf("%s\n", dst3);
	printf("%s\n", src0);
	if (ft == 1)
		res = ft_strlcat(dst3, src0, len);
	else
		res = strlcat(dst3, src0, len);
	printf("%s\n", dst3);
	printf("%zu\n", res);

/*
	//Test 3b: Testing with normal dst & src
	//Negative n; libc errors - UB?
	len = -5;
	printf("%s\n", dst3);
	printf("%s\n", src0);
	if (ft == 1)
		res = ft_strlcat(dst3, src0, len);
	else
		res = strlcat(dst3, src0, len);
	printf("%s\n", dst3);
	printf("%zu\n", res);
*/
/*
	//Test 4: weird input, n = NULL
	//Compile errors 2x;
	printf("%s\n", dst3);
	printf("%s\n", src0);
	if (ft == 1)
		res = ft_strlcat(dst3, src0, NULL);
	else
		res = strlcat(dst3, src0, NULL);
	printf("%s\n", dst3);
	printf("%zu\n", res);
*/
/*
	//Test 5: dst/src is NULL
	//libc/libft seg fault
	char	dst5[50] = "12345";;
	char	src5[50] = "abcde";
	len = 15;
	printf("%s\n", dst5);
	printf("%s\n", src5);
	if (ft == 1)
		res = ft_strlcat(dst5, NULL, len);
	else
		res = strlcat(dst5, NULL, len);
	printf("%s\n", dst5);
	printf("%zu\n", res);
*/
	//Test 6: dst/src empty
	//libc/libft seg fault
	char	dst6[50] = "12345";;
	char	src6[50] = "";
	len = 15;
	printf("%s\n", dst6);
	printf("%s\n", src6);
	if (ft == 1)
		res = ft_strlcat(dst6, src6, len);
	else
		res = strlcat(dst6, src6, len);
	printf("%s\n", dst6);
	printf("%zu\n", res);

/*
	//Test 7: dst/src buffer too small
	//libc abort - UB?
	char	dst7[8] = "12345";;
	char	src7[8] = "abcde";
	len = 9;
	printf("%s\n", dst7);
	printf("%s\n", src7);
	if (ft == 1)
		res = ft_strlcat(dst7, src7, len);
	else
		res = strlcat(dst7, src7, len);
	printf("%s\n", dst7);
	printf("%zu\n", res);
*/
}
