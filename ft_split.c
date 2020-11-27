/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 16:28:19 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/27 09:22:31 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>
#include <string.h>

/*
** Function to free all memory, only used if some string allocation fails.
*/

static	void	free_strings(char **ret, size_t n)
{
	while (n > 0)
	{
		n--;
		free(*(ret + n));
	}
	free(ret);
}

static	size_t	count_strings(char *s, char d)
{
	size_t	strings;
	char	*sep0;

	sep0 = s - 1;
	strings = 0;
	while (1)
	{
		if (*s == d || *s == '\0')
		{
			if (s - sep0 > 1)
				strings++;
			if (*s == '\0')
				return (strings);
			sep0 = s;
		}
		s++;
	}
	return (strings);
}

static int		cpy_strings(char *s, size_t n, char d, char **ret)
{
	size_t	i;
	char	*s_end;

	s_end = s;
	i = 0;
	while (i < n)
	{
		while (*s == d)
			s++;
		s_end = ft_strchr(s, d);
		if (i + 1 == n && s_end == NULL)
			s_end = s + ft_strlen(s);
		*(ret + i) = ft_strndup(s, s_end - s);
		if (*(ret + i) == NULL)
		{
			free_strings(ret, i);
			return (0);
		}
		s = s_end;
		i++;
	}
	*(ret + n) = NULL;
	return (1);
}

char			**ft_split(char const *s, char c)
{
	char	**result;
	size_t	n_strings;

	if (s == NULL)
		return (NULL);
	n_strings = count_strings((char*)s, c);
	result = malloc((n_strings + 1) * sizeof(char*));
	if (result == NULL)
		return (NULL);
	if (cpy_strings((char*)s, n_strings, c, result) == 0)
		return (NULL);
	return (result);
}
