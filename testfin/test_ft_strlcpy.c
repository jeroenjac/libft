/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strlcpy.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 13:09:38 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/29 23:08:05 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>
#include <stdio.h>
#include "inittest.c"

/*
** TEST SCEN
** 0. Libc
** 1. Libft
** 4. Libc error
** 5. Libf error
*/

int		main(int argc, char **argv)
{
	int		ft;

	printf("prog: %s\n", argv[0]);
    ft = inittest(argc, "ft_strlcpy");	
	
	size_t	len;
	size_t	res;
	
	//Test 0: Happy flow: normal input diff strings
	char	dst0[30] = "codam in amsterdam";
	char	src0[30] = "ABCDEFGHIJ";
	len = 4;
	if (ft < 2)
	{
		printf("%s\n", dst0);
		printf("%s\n", src0);
	}
	if (ft == 1)
		res = ft_strlcpy(dst0, src0, len);
	if (ft == 0)
		res = strlcpy(dst0, src0, len);
	if (ft < 2)
	{
		printf("%s\n", dst0);
		printf("%zu\n", res);
	}
	
	//Test 1: n = 0;
	char	dst1[30] = "codam campus";
	len = 0;
	if (ft < 2)
	{
		printf("%s\n", dst1);
		printf("%s\n", src0);
	}
	if (ft == 1)
		res = ft_strlcpy(dst1, src0, len);
	if (ft == 0)
		res = strlcpy(dst1, src0, len);
	if (ft < 2)
	{
		printf("%s\n", dst1);
		printf("%zu\n", res);
	}

	//Test 2: n > size of src
	char	dst2[30] = "2 codam campus";
	char	src2[30] = "nok";
	len = 10;
	if (ft < 2)
	{
		printf("%s\n", dst2);
		printf("%s\n", src2);
	}
	if (ft == 1)
		res = ft_strlcpy(dst2, src2, len);
	if (ft == 0)
		res = strlcpy(dst2, src2, len);
	if (ft < 2)
	{
		printf("%s\n", dst2);
		printf("%s\n", dst2 + 4); //To print after src
		printf("%zu\n", res);
	}

	//Test 3: n > #chars of dst
	char	dst3[30] = "3 codam campus";
	char	src3[30] = "3no";
	len = 20;
	if (ft < 2)
	{
		printf("%s\n", dst3);
		printf("%s\n", src3);
	}
	if (ft == 1)
		res = ft_strlcpy(dst3, src3, len);
	if (ft == 0)
		res = strlcpy(dst3, src3, len);
	if (ft < 2)
	{
		printf("%s\n", dst3);
		printf("%s\n", dst3 + 4);
		printf("%zu\n", res);
	}
/*
	//Test 4: n > size of  dst
	//libc & libft --> zsh: abort.
	char	dst4[10] = "4 codam";
	char	src4[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	len = 20;
	printf("%s\n", dst4);
	printf("%s\n", src4);
	if (ft == 1)
		res = ft_strlcpy(dst4, src4, len);
	else
		res = strlcpy(dst4, src4, len);
	printf("%s\n", dst4);
	printf("%zu\n", res);
*/

	//Test 5: size of src too small for \0
	//ASAN ISSUE
	char	dst5[30] = "5 codam campus";
	char	src5[4] = "5nok";
	len = 10;
	if (ft < 2)
	{
		printf("%s\n", dst5);
		printf("%s\n", src5);	
	}
	if (ft == 1)
		printf("strlen src = %lu\n", ft_strlen(src5));
	if (ft == 0)
		printf("strlen src = %lu\n", strlen(src5));
	if (ft == 1)
		res = ft_strlcpy(dst5, src5, len);
	if (ft == 0)
		res = strlcpy(dst5, src5, len);
	if (ft < 2)
	{
		printf("%s\n", dst5);
		printf("%zu\n", res);
	}
/*
	//Test 6: src is NULL (direct)
	//libc & libft segfault
	char	dst6[30] = "6 codam campus";
	len = 10;
	printf("%s\n", dst6);
	if (ft == 1)
		res = ft_strlcpy(dst6, NULL, len);
	if (ft == 0)
		res = strlcpy(dst6, NULL, len);
	printf("%s\n", dst6);
	printf("%zu\n", res);
*/
	//Test 7: dst is NULL (direct)
	//libc seg fault, libft protected?:
	char	src7[20] = "abcde12345abcde1234";
	len = 10;
	if (ft == 5)
		res = ft_strlcpy(NULL, src7, len);
	if (ft == 4)
		res = strlcpy(NULL, src7, len);
	printf("%zu\n", res);
}
