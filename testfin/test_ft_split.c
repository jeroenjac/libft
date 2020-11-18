/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_split.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 16:56:26 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/19 00:36:14 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

#include "inittest.c"

//for testing (also helperfunction of ft_split.c)
int		count_strings(char *s, char d);
void	printss(char **dbp);
void	freess(char **dbp);

int		main(int argc, char **argv)
{
	int		ft;

	printf("prog: %s\n", argv[0]);
	ft = inittest(argc, "ft_split");
/*
	//random stuff
	char	*test = "test111";
	char	*ptt;

	ptt = ft_strchr(test, '1');
	printf("%s\n", ptt);

	printf("Diff in positions = %li\n", ptt - test);

	char	d = '1';
	printf("test: %s\n", ft_strtrim("1", "1"));
	printf("test2: %i\n", *ft_strtrim("1", "1") != d);
*/
/*
	//prototyping count_strings
	char	c = '1';
	printf("# strings = %i\n", count_strings("", c));
	printf("# strings = %i\n", count_strings("1", c));
	printf("# strings = %i\n", count_strings("1111", c));
	printf("# strings = %i\n", count_strings("test", c));
	printf("# strings = %i\n", count_strings("1test", c));
	printf("# strings = %i\n", count_strings("test1", c));
	printf("# strings = %i\n", count_strings("1111test", c));
	printf("# strings = %i\n", count_strings("test1111", c));
	printf("# strings = %i\n", count_strings("test1test", c));
	printf("# strings = %i\n", count_strings("test1111test", c));
	printf("# strings = %i\n", count_strings("test11test1test1111test11", c));
*/
	char **testsplit;

	//char	*test = NULL;
	//char	*test = "hallo wat ben ik aan het doen ";
	char	test[] = "Jeroen999Sophie";
	char	del = '9';
	printf("# strings = %i\n", count_strings((char*)test, del));

	testsplit = ft_split(test, del);
	printss(testsplit);
	
	freess(testsplit);
	free(testsplit);
}

void	printss(char **dbp)
{
	int		w;

	w = 0;
	while (*(dbp + w) != NULL)
	{
		printf("s%i: %s\n", w, *(dbp + w));
		w++;
	}
}

void	freess(char **dbp)
{
	int		w;

	w = 0;
	while (*(dbp + w) != NULL)
	{
		free(*(dbp + w));
		w++;
	}
}
