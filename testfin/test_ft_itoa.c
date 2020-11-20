/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_itoa.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 16:59:14 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/20 18:09:01 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//Tests
// 0
// negative
// -0?
// INTMAX
// Test using atoi?

#include "../libft.h"
#include <stdio.h>
#include "inittest.c"

/*
** Testing modes
** 1: Prototyping
*/

int		main(int argc, char **argv)
{
	int		ft;

	printf("prog: %s\n", argv[0]);
	ft = inittest(argc, "ft_itoa");

	char	*ret;
	ret = ft_itoa(12);
	printf("%s\n", ret);
}
