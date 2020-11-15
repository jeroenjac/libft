/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_bzero.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 17:43:08 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/15 23:53:07 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "inittest.c"

int		inittest(int argc, char *ftname);

int     main(int argc, char **argv)
{
    int     ft;

    printf("prog: %s\n", argv[0]);
    ft = inittest(argc, "ft_bzero");
	
	//Section 1: Functional tets
    char    str0[60] = "yesyes";
    size_t  len;

    len = 50;
    if (ft < 2)
        printf("Before: %s\n", str0);
    if (ft == 0)
        bzero(str0, len);
    if (ft == 1)
        ft_bzero(str0, len);
    if (ft < 2)
        printf("After: %s\n", str0);

    //Special case where last char of string is set to not \0,
    char    str1[6] = "hallo";

    len = 1;
    if (ft < 2)
        printf("Before: %s\n", str1);
    if (ft == 0)
        bzero(str1 + 5, len);
    if (ft == 1)
        ft_bzero(str1 + 5, len);
    if (ft < 2)
        printf("After: %s\n", str1);

	//Testing with arrays of ints
    int     arr1[10];
	arr1[3] = 65536 + 7; //65536 = 0b0..0-00000001-0..0-00000111

    len = 2*sizeof(int);
    if (ft < 2)
        printf("Before bzero(len = 2 * intsize), arr[3] = %d\n", arr1[3]);
    if (ft == 0)
        bzero(arr1, len);
    if (ft == 1)
        ft_bzero(arr1, len);
    if (ft < 2)
        printf("After bzero(len = 2 * intsize), arr[3] = %d\n", arr1[3]);
    len = 3*sizeof(int) + 2; // Only 2 bytes of arr[3] --> should subtract 7 here.
    if (ft < 2)
        printf("Before bzero(len = 14), arr[3] = %d\n", arr1[3]);
    if (ft == 0)
        bzero(arr1, len);
    if (ft == 1)
        ft_bzero(arr1, len);
    if (ft < 2)
        printf("After bzero(len = 14), arr[3] = %d\n", arr1[3]);
    len = 4*sizeof(int); // Full arr[3], see calc above.
    if (ft < 2)
        printf("Before bzero(len = 4 * intsize), arr[3] = %d\n", arr1[3]);
    if (ft == 0)
        bzero(arr1, len);
    if (ft == 1)
        ft_bzero(arr1, len);
    if (ft < 2)
        printf("After bzero(len = 4 * intsize), arr[3] = %d\n", arr1[3]);

	//Testing with arrays of ints -- 2
	int		arr2[10];
	int		i;

	i = -1;
	while (i++ < 9)
	{
		arr2[i] = i + 1;
		//printf("i = %i\n", i);
	}

	len = 4*sizeof(int);
	
	if (ft < 2)
		printf("Before bzero(), arr[3]: %d\n", arr2[3]);
	if (ft == 0)
		bzero(arr2, len);
	if (ft == 1)
		ft_bzero(arr2, len);
	if (ft < 2)
		printf("After ft_bzero(), arr[3]: %d\n", arr2[3]);	   
	
	//Testing with len = 0 & negative;
	char name[10] = "Amsterdam";
	
	len = 0;
	if (ft < 2)
		printf("Before: %s\n", name);
	if (ft == 0)
		bzero(name, len);
	if (ft == 1)
		ft_bzero(name, len);
	if (ft < 2)
		printf("After: %s\n", name);

/*
	//negative: libc aborts, libft segfault
	len = -2;
	if (ft < 2)
		printf("Before: %s\n", name);
	if (ft == 0)
		bzero(name, len);
	if (ft == 1)
		ft_bzero(name, len);
	if (ft < 2)
		printf("After: %s\n", name);
*/
/*
	//Testing with str = NULL
	//libc and libft segfault
	if (ft == 0)
		bzero(NULL, 1);
	if (ft == 1)
		ft_bzero(NULL, 1);
*/
}
