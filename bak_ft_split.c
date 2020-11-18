/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 16:28:19 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/18 14:00:35 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h> // Remove

/*
** Approach
** 1. Find # of strings, by counting c in *s (~strchr). [ FUN 1 ]
** 2. Malloc **result using (1). Incl. space for term. NULL ptr. Calloc? [ MAIN ]
** 3a. While loop for every string (based on 1) [ MAIN ].
** 3b. Find c0, c1, etc.
** 4. Take substring (~ft_substr) and put *subres in **result.
** 5. Do this until loop find '\0' (end of string s)
** 6. Add NULL
*/
	
/*
** Function calculates number of strings in s, using c as delimeter, e.g.;
** "sscsas" = 2 (ss and sas)
** "csscsas" = 2 (ss and sas) no "" in begin.
** "testcctest" = 2 ("", ss and sas) no "" in between.
** "" = 0 (""). End result is only NULL
*/

//Should be static declared to avoid publish?
int		count_strings(char *s, char d)
{
	int		strings;
	char	*del1;
	char	*del2;

	s = ft_strtrim(s, &d);
	printf("input = %s, ", s);
	if (*s == '\0')
		return (0);
	del1 = ft_strchr(s, d);
	del2 = ft_strchr(s + 1, d);
	if (del1 == NULL && del2 == NULL)
		return (1);
	strings = 0;
	while (del2 != NULL && del1 != NULL)
	{
		if (del2 != del1 + 1)
			strings++;
		del1 = del2;
		if (del1 != NULL)
			del2 = ft_strchr(del1 + 1, d);
	}
	return (strings);
}

char	**ft_split(char const *s, char c)
{
	int		nstr;
	int		len;
	char	**result;
	int		sub[3];

	len = ft_strlen(s);
	sub[0] = 0;
	//sub[1] = len - ft_strlen
	nstr = 3;
	//nstr = count_strings((char*)s, c);;
	result = malloc(3 * sizeof(char*));
	*result = NULL;

	//Used for prototype / to be deleted.
	char	**ret;
	char	*sp1;
	char	*sp2;

	c = 's';
	sp1 = ft_strdup("Split");
	sp2 = ft_strdup(s);
	ret = malloc(3 * sizeof(*sp1));
	ret[0] = sp1;
	ret[1] = sp2;
	ret[2] = NULL;
	
	return (ret);
}
