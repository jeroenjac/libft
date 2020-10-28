/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeroen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:27:19 by Jeroen            #+#    #+#             */
/*   Updated: 2020/10/27 16:52:05 by Jeroen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	tests[40]="hallo";
	int		len;

	len = 3;

	printf("Input: %s\n", tests);
	bzero(tests, len);
	printf("Output: %s\n", tests);
	
	char	tests2[40]="hallo";
	char	*p;

	printf("Input: %s\n", tests2);
	p = tests2;
	while (len > 0)
	{
		*p = '0';
		len--;
		p++;
	}
	printf("Output: %s\n", tests2);
}
