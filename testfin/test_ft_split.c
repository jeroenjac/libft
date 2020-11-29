/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_split.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 16:56:26 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/27 11:41:08 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inittest.c"

void	printss(char **dbp);
void	freess(char **dbp);

//for testing (also helperfunction of ft_split.c)
size_t	count_strings(char *s, char d);

//Available testing modes
//0. Some unstructured manual tests
//1. Some structured tests
//4. To test count_strings (crucial for ft_split...)

int		main(int argc, char **argv)
{
	int		ft;

	printf("prog: %s\n", argv[0]);
	ft = inittest(argc, "ft_split");

	char	del;

//Some tests, easy to change by hand
if (ft == 0)
{
	
	printf("Testing ft_split function...\n");
	char	**split_test1;
	char	**split_test2;
	char	*testss;
	char	*testss2;

	testss = strdup("end of line \0 or not?");
	del = '\0';
	//printf("# strings = %zu\n", count_strings((char*)testss, del));
	split_test1 = ft_split(testss, del);
	
	free(testss);
	
	printss(split_test1);
	freess(split_test1);
	free(split_test1);


	testss2 = strdup(",jan,,,pete,,,,kevin:,,,,");
	del = ',';
	split_test2 = ft_split(testss2, del);
	free(testss2);
	
	printss(split_test2);
	freess(split_test2);
	free(split_test2);
}
//All different possible tests scenarios with & withouth del etc.
if (ft == 1)
{
	char dela = 'd'; //Should be 'd' for structured tests.
	int	ntests = 12; //Number of tests + terminating NULL pointer.
	char **testcases;
	testcases = malloc((ntests + 1) * sizeof (char *));
	
	*(testcases + 0) = ft_strdup("");
	*(testcases + 1) = ft_strdup("d");
	*(testcases + 2) = ft_strdup("ddddddd");
	*(testcases + 3) = ft_strdup("test4");
	*(testcases + 4) = ft_strdup("dtest5");
	*(testcases + 5) = ft_strdup("test6d");
	*(testcases + 6) = ft_strdup("dddddtest7");
	*(testcases + 7) = ft_strdup("test8ddddd");
	*(testcases + 8) = ft_strdup("test9dtest9");
	*(testcases + 9) = ft_strdup("test10dddddtest10");
	*(testcases + 10) = ft_strdup("test11dddd11dddttttdtdtdt");
	*(testcases + 11) = NULL;

	char ***splitresults;
	int wt = 0;
	splitresults = malloc((ntests + 1) * sizeof (char *));
	while (*(testcases + wt) != NULL)
	{
		*(splitresults + wt) = ft_split(testcases[wt], dela);
		wt++;
	}
	*(splitresults + wt) = NULL;
	
	wt = 0;
	while (*(splitresults + wt) != NULL)
	{
		printf("Test %i: split \"%s\". Delimeter = %c\n", wt + 1, testcases[wt], dela);
		printss(*(splitresults + wt));
		wt++;
	}
}
//A single "automated" test
	if (ft == 3)
	{
		char	*autotest = ft_strdup("1111test11dddd11dddttttdtdt1d1t1111");
		char	delim = '1';
		char	*autoresult[6] = {"test", "dddd", "dddttttdtdt", "d", "t", NULL};
		char	**testresult = ft_split(autotest, delim);
		int		succes = 1;
		int		i = 0;
		while (autoresult[i] != NULL)
		{
			if (strcmp(testresult[i], autoresult[i]) != 0)
			{
				succes = 0;
				printf("ft_split: %-10s\texpected:%-10s\n", testresult[i],\
				autoresult[i]);
			}
			i++;
		}
		if (succes == 0)
			printf("TEST FAILED\n");
		else
			printf("TEST PASSED\n");
	}
	if (ft == 5)
	{
		printss(ft_split(NULL, 'a'));
	}

//A test that failed while others succeeded
if (ft == 0)
{
	char	test2[] = "hallo wat ben ik aan het doen ";
	char	**split3;
	
	del = 'l';
	//printf("# strings = %i\n", count_strings((char*)test2, del));
	split3 = ft_split(test2, del);
	printss(split3);
}	

//Used to protype count_strings - make sure count_strings is not static.

/*
if (ft == 4)
{
	char	c = '1';
	printf("Testing count_strings function...\n");
	printf("# strings = %zu\n", count_strings("", c));
	printf("# strings = %zu\n", count_strings("1", c));
	printf("# strings = %zu\n", count_strings("1111", c));
	printf("# strings = %zu\n", count_strings("test", c));
	printf("# strings = %zu\n", count_strings("1test", c));
	printf("# strings = %zu\n", count_strings("test1", c));
	printf("# strings = %zu\n", count_strings("1111test", c));
	printf("# strings = %zu\n", count_strings("test1111", c));
	printf("# strings = %zu\n", count_strings("test1test", c));
	printf("# strings = %zu\n", count_strings("test1111test", c));

	printf("# strings = %lu\n", count_strings("test11test1test1111test11", '1'));
}	
*/

	//random stuff I used for testing parts of split function
/*
	char	*test = "test111";
	char	*ptt;

	ptt = ft_strchr(test, '1');
	printf("%s\n", ptt);

	printf("Diff in positions = %li\n", ptt - test);

	char	d = '1';
	printf("test: %s\n", ft_strtrim("1", "1"));
	printf("test2: %i\n", *ft_strtrim("1", "1") != d);

	char	s[10] = "aaaba";
	if (strchr(s, 'b') == s + 3 )
		printf("Hoera\n");
	//printf("%s\n", s - 2);

	char *dup1;
	//char *dup2;

	dup1 = strndup("hallo56789", -1);
	size_t stn = -1;
	printf("size_t neg = %zu\n", stn);
	printf("%s\n", dup1);
	//dup1 = ft_strndup("hallo56789", -7);
	//printf("%s\n", dup1);
*/
}

//Two helper functions for testing: 
// 1. print results
// 2. free result - not needed?

void	printss(char **dbp)
{
	int		w;

	w = 0;
	while (*(dbp + w) != NULL)
	{
		printf("s%i: %s\n", w, *(dbp + w));
		w++;
	}
	printf("s%i: %s\n", w, *(dbp + w));
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
	free (*(dbp + w));
}
