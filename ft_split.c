/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 16:28:19 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/19 00:08:35 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

/*
**Should be static declared to avoid publish?
*/

int		count_strings(char *s, char d)
{
	int		strings;
	char	*s_trimd;

	strings = 0;
	while (s != NULL)
	{
		s_trimd = ft_strtrim(s, &d);
		if (*s_trimd != '\0')
			strings++;
		s = ft_strchr(s_trimd, d);
		free(s_trimd);
	}
	return (strings);
}

char	**cpy_strings(char *s, int n, char d, char **ret)
{
	int		i;
	char	*s_begin;
	char	*s_end;
	size_t	s_len;

	i = 0;
	s_end = s;
	while (i < n)
	{
		s_begin = ft_strtrim(s_end, &d);
		if (s_begin == NULL)
			return (NULL);
		if (i == n - 1)
			d = '\0';
		s_end = ft_strchr(s_begin, d);
		s_len = ft_strlen(s_begin) - ft_strlen(s_end);
		*(ret + i) = ft_strndup(s_begin, s_len);
		if (*(ret + i) == NULL)
			return (NULL);
		i++;
		free(s_begin);
	}
	*(ret + n) = NULL;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		n_strings;

	printf("input0: %s\n", s);
	n_strings = count_strings((char*)s, c);
	printf("input1: %s\n", s);
	result = malloc(n_strings * sizeof(char*));
	if (result == NULL)
		return (NULL);
	result = cpy_strings((char*)s, n_strings, c, result);
	printf("input3: %s\n", s);
	return (result);
}
