/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 16:28:19 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/12/14 16:40:49 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Function to free all memory, only used if some string allocation fails.
*/

static	void	free_strings(char **strings, size_t n)
{
	while (n > 0)
	{
		n--;
		free(strings[n]);
	}
	free(strings);
}

/*
** Function counts the number of 'words' in the given string s
** Method
** - Pointer is moved along s, one char by one.
** - Pointer to last delimeter is stored
** - When a (new) delimeter char is found in s:
**		- check if prevdelim  > 1 away (e.g. dddcddd) -> word in between ('c')
** - Else, continue to next char
*/

static	size_t	count_strings(char *s, char d)
{
	size_t	wordcount;
	char	*prevdelim;

	prevdelim = s - 1;
	wordcount = 0;
	while (1)
	{
		if (*s == d || *s == '\0')
		{
			if (s - prevdelim > 1)
				wordcount++;
			if (*s == '\0')
				return (wordcount);
			prevdelim = s;
		}
		s++;
	}
}

static int		copytostrings(char *s, size_t n, char d, char **strings)
{
	size_t	w;
	char	*nextdelim;

	nextdelim = s;
	w = 0;
	while (w < n)
	{
		while (*s == d)
			s++;
		nextdelim = ft_strchr(s, d);
		if (w + 1 == n && nextdelim == NULL)
			nextdelim = s + ft_strlen(s);
		strings[w] = ft_strndup(s, nextdelim - s);
		if (strings[w] == NULL)
		{
			free_strings(strings, w);
			return (0);
		}
		s = nextdelim;
		w++;
	}
	strings[n] = NULL;
	return (1);
}

char			**ft_split(char const *s, char c)
{
	char	**result;
	size_t	numofstrings;

	if (s == NULL)
		return (NULL);
	numofstrings = count_strings((char*)s, c);
	result = ft_calloc((numofstrings + 1), sizeof(char*));
	if (result == NULL)
		return (NULL);
	if (copytostrings((char*)s, numofstrings, c, result) == 0)
		return (NULL);
	return (result);
}
