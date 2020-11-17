/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strdup.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 21:10:44 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/17 12:50:00 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "inittest.c"

#include <string.h>
#include <stdlib.h>
#include "../libft.h"

//Is this needed?
int		inittest(int argc, char *ftname);


int		main(int argc, char **argv)
{
	int		ft;

	printf("prog: %s\n", argv[0]);
	ft = inittest(argc, "ft_strdup");

	// t1: simple.
	char	sorg1[] = "Hello";
	char	*sdup1 = NULL;
	//char	sdup1[50] = "Cake"	// Such test does not work, since char arr is not assignable

	if (ft < 2)
	{
		printf("Orig: %s\n", sorg1);
		printf("Copy: %s\n", sdup1);
	}
	if (ft == 0)
		sdup1 = strdup(sorg1);
	if (ft == 1)
		sdup1 = ft_strdup(sorg1);
	if (ft < 2)
	{
		printf("Orig: %s\n", sorg1);
		printf("Copy: %s\n", sdup1);
	}
	free(sdup1);

/*
	// t2: original = NULLi (direct);
	// libc & libft segfault
	char	*sdup2 = NULL;

	printf("Copy: %s\n", sdup2);
	if (ft == 0)
		sdup2 = strdup(NULL);
	if (ft == 1)
		sdup2 = ft_strdup(NULL);
	printf("Copy: %s\n", sdup2);

	free(sdup2);
*/

	// t3: original = "";
	char	sorg3[] = "";
	char	*sdup3 = NULL;

	if (ft < 2)
	{
		printf("Orig: %s\n", sorg3);
		printf("Copy: %s\n", sdup3);
	}
	if (ft == 0)
		sdup3 = strdup(sorg3);
	if (ft == 1)
		sdup3 = ft_strdup(sorg3);
	if (ft < 2)
	{	
		printf("Orig: %s\n", sorg3);
		printf("Copy: %s\n", sdup3);
	}
	free(sdup3);
	
	// t4: libc == libft direct compare
	char	sorg4[] = "Codam copy cats";
	char	*sdup4a = NULL;
	char	*sdup4b = NULL;
	int		comp;

	if (ft == 2)
		printf("Orig: %s\n", sorg4);
	sdup4a = strdup(sorg4);
	sdup4b = ft_strdup(sorg4);
	comp = ft_strncmp(sdup4a, sdup4b, ft_strlen(sdup4a));
	if (ft == 2)
		printf("Comparing strdup result (libc vs Libft): %i\n", comp == 0);
	
	free(sdup4a);
	free(sdup4b);
	
	// t5: dup3 = dup2 = dup1 = orig
	char	sorg5[] = "Codam goes coding: libft time";
	char	*sdup51 = NULL;
	char	*sdup52 = NULL;
	char	*sdup53 = NULL;

	if (ft < 2)
	{
		printf("Orig: %s\n", sorg5);
		printf("Copy: %s\n", sdup53);
	}
	if (ft == 0)
	{
		sdup51 = strdup(sorg5);
		sdup52 = strdup(sdup51);
		sdup53 = strdup(sdup52);
	}
	if (ft == 1)
	{
		sdup51 = ft_strdup(sorg5);
		sdup52 = ft_strdup(sdup51);
		sdup53 = ft_strdup(sdup52);
	}
	if (ft < 2)
	{	
		printf("Orig: %s\n", sorg5);
		printf("Copy: %s\n", sdup53);
	}
	free(sdup51);
	free(sdup52);
	free(sdup53);
}
