/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_memcmp.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 22:28:03 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/10 18:34:57 by jjacobs       ########   odam.nl         */
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
	
	//Test 0: Happy flow: normal input diff strings
	char	dst0[30] = "codam in amsterdam";
	char	src0[30] = "ABCDEFGHIJ";
	len = 4;
	printf("%s\n", dst0);
	printf("%s\n", src0);
	if (ft == 1)
		res = ft_strlcpy(dst0, src0, len);
	else
		res = strlcpy(dst0, src0, len);
	printf("%s\n", dst0);
	printf("%zu\n", res);
	
	//Test 1: n = 0;
	char	dst1[30] = "codam campus";
	len = 0;
	printf("%s\n", dst1);
	printf("%s\n", src0);
	if (ft == 1)
		res = ft_strlcpy(dst1, src0, len);
	else
		res = strlcpy(dst1, src0, len);
	printf("%s\n", dst1);
	printf("%zu\n", res);
	
	//Test 2: n > size of src
	char	dst2[30] = "2 codam campus";
	char	src2[30] = "nok";
	len = 10;
	printf("%s\n", dst2);
	printf("%s\n", src2);
	if (ft == 1)
		res = ft_strlcpy(dst2, src2, len);
	else
		res = strlcpy(dst2, src2, len);
	printf("%s\n", dst2);
	printf("%s\n", dst2 + 4); //To print after src
	printf("%zu\n", res);
	
	//Test 3: n > #chars of dst
	char	dst3[30] = "3 codam campus";
	char	src3[30] = "3no";
	len = 20;
	printf("%s\n", dst3);
	printf("%s\n", src3);
	if (ft == 1)
		res = ft_strlcpy(dst3, src3, len);
	else
		res = strlcpy(dst3, src3, len);
	printf("%s\n", dst3);
	printf("%s\n", dst3 + 4);
	printf("%zu\n", res);

/*
	//Test 4: n > size of  dst
	//Both zsh: abort.
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
	char	dst5[30] = "5 codam campus";
	char	src5[4] = "5nok";
	len = 10;
	printf("%s\n", dst5);
	printf("%s\n", src5);	
	if (ft == 1)
		printf("strlen src = %lu\n", ft_strlen(src5));
	else
		printf("strlen src = %lu\n", strlen(src5));
	if (ft == 1)
		res = ft_strlcpy(dst5, src5, len);
	else
		res = strlcpy(dst5, src5, len);
	printf("%s\n", dst5);
	printf("%zu\n", res);

/*
	//Test 6: dst/src is NULL
	char	dst6[30] = "6 codam campus";
	char	src6[30] = "6nok";
	len = 10;
	printf("%s\n", dst6);
	if (ft == 1)
		printf("strlen src = %lu\n", ft_strlen(src6));
	else
		printf("strlen src = %lu\n", strlen(src6));
	if (ft == 1)
		res = ft_strlcpy(dst6, NULL, len);
	else
		res = strlcpy(dst6, NULL, len);
	printf("%s\n", dst6);
	printf("%zu\n", res);
*/
}
