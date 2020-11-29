/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_calloc.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 13:24:39 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/27 11:27:31 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "inittest.c"

#include <stdlib.h>
#include "../libft.h"

int     inittest(int argc, char *ftname);

int     main(int argc, char **argv)
{
    int     ft;

    printf("prog: %s\n", argv[0]);
    ft = inittest(argc, "ft_calloc");

    //Section 1: Simple test: reserve for 10 * int?
	size_t			c1;
	size_t			s1;
	int				*rp1;
	int				*rp2;
	unsigned int	i;
	unsigned int	imax;

	c1 = 10;
	s1 = sizeof(int);
	printf("Calloc test (c1 = %zu, s1 = %zu)\n", c1, s1);
	if (ft == 0)
		rp1 = (int*)calloc(c1, s1);
	if (ft == 1)
		rp1 = (int*)ft_calloc(c1, s1);
	printf("Size of result (sizeof(*rp1)): %zu\n", sizeof(*rp1));
	printf("Size of result (sizeof(rp1)): %zu\n", sizeof(rp1)); // addr = 8 bytes?
	//printf("Result (rp1): %p\n", rp1);	//print ptr = address of mem, changes
	//printf("Result (&rp1): %p\n", &rp1);	//print addres of ptr, changes
	rp2 = malloc(c1 * s1);
	imax = c1 + 0; // enter more numbers than calloced/malloced?

	//For demo - show what is in the mem. Calloc -> 0, Malloc -> random.
	printf("Data calloc: ");
	i = 0;
	while (i < imax)
	{
		printf ("%d ", rp1[i]);
		i++;
	}
	/*
	printf("\nData malloc: ");
	i = 0;
	while (i < imax)
	{
		printf ("%d ", rp2[i]);
		i++;
	}
	*/
	printf("\n");
	
	free (rp1);
	free (rp2);

	//Section 2: Test with x chars
	char			*rp3;
	char			*rp4;
	c1 = 40;
	s1 = sizeof(char);
	printf("Calloc test (c1 = %zu, s1 = %zu)\n", c1, s1);
	if (ft == 0)
		rp3 = calloc(c1, s1);
	if (ft == 1)
		rp3 = ft_calloc(c1, s1);
	rp4 = malloc(c1 * s1);
	if (rp3 == NULL)
		printf("Calloc failed\n");
	//For demo - show what is in the mem. Calloc -> 0, Malloc -> random.
	//If these are string, bzero set them to 0b0..0 == '\0'. So nth printed.
	printf("Data calloc: %s\n", rp3);
	//printf("Data malloc: %s\n", rp4);
	printf("Data calloc (hex): ");
	i = 0;
	while (i < imax)
	{
		printf ("%02X ", rp3[i]);
		i++;
	}
	printf("\n");
	/*
	printf("\nData malloc (hex): ");
	i = 0;
	while (i < imax)
	{
		printf ("%02X ", rp4[i]);
		i++;
	}
	printf("\n");
	*/
	free (rp3);
	free (rp4);

	//Section 3: Test with c1 = 0;
	c1 = 0;
	s1 = sizeof(int);
	printf("Calloc test (c1 = %zu, s1 = %zu)\n", c1, s1);
	if (ft == 0)
		rp1 = calloc(c1, s1);
	if (ft == 1)
		rp1 = ft_calloc(c1, s1);
	if (rp1 == NULL)
		printf("Calloc failed\n");
	rp2 = malloc(c1 * s1);
	if (rp2 == NULL)
		printf("Malloc failed\n");
	
	free(rp1);
	free(rp2);
	
	//Section 4: Test with s1 = 0;
	c1 = 100;
	s1 = 0;
	printf("Calloc test (c1 = %zu, s1 = %zu)\n", c1, s1);
	if (ft == 0)
		rp1 = calloc(c1, s1);
	if (ft == 1)
		rp1 = ft_calloc(c1, s1);
	if (rp1 == NULL)
		printf("Calloc failed\n");
	rp2 = malloc(c1 * s1);
	if (rp2 == NULL)
		printf("Malloc failed\n");
	
	free(rp1);
	free(rp2);
	
	//Section 4b: Test with s1 = 0 & c1 = 0;
	c1 = 0;
	s1 = 0;
	printf("Calloc test (c1 = %zu, s1 = %zu)\n", c1, s1);
	if (ft == 0)
		rp1 = calloc(c1, s1);
	if (ft == 1)
		rp1 = ft_calloc(c1, s1);
	if (rp1 == NULL)
		printf("Calloc failed\n");
	rp2 = malloc(c1 * s1);
	if (rp2 == NULL)
		printf("Malloc failed\n");
	
	free(rp1);
	free(rp2);
	
	//Section 5: Test for A LOT OF mem
	c1 = 1e8;
	s1 = sizeof(int);;
	printf("Calloc test (c1 = %zu, s1 = %zu)\n", c1, s1);
	if (ft == 0)
		rp1 = calloc(c1, s1);
	if (ft == 1)
		rp1 = ft_calloc(c1, s1);
	if (rp1 == NULL)
		printf("Calloc failed\n");
	rp2 = malloc(c1 * s1);
	if (rp2 == NULL)
		printf("Malloc failed\n");
	
	free(rp1);
	free(rp2);
	
	//Section 6: Test for malloc fail
	c1 = 1;
	s1 = -1; // Likely always leads to fail?
	if (ft == 4 || ft == 5)
		printf("Calloc test (c1 = %zu, s1 = %zu)\n", c1, s1);
	if (ft == 4)
		rp1 = calloc(c1, s1);
	if (ft == 5)
		rp1 = ft_calloc(c1, s1);
	if (rp1 == NULL)
		printf("Calloc failed\n");
	if (ft == 4 || ft == 5)
		rp2 = malloc(c1 * s1);
	if (rp2 == NULL)
		printf("Malloc failed\n");
	
	if (ft == 4 || ft == 5)
		free(rp1);
	if (ft == 4 || ft == 5)
		free(rp2);
}
