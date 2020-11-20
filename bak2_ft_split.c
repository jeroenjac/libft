/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 16:28:19 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/19 15:06:00 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h> // Remove

static	void	free_strings(char	**strings, size_t n)
{
	while (n > 0)
	{
		n--;
		free(*(strings + n));
	}
	free(strings);
}

//Make static
size_t			count_strings(char *s, char d)
{
	size_t	strings;
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

void			cpy_strings(char *s, size_t n, char d, char **ret)
{
	size_t	i;
	char	*s_begin;
	char	*s_end;
	size_t	s_len;

	i = 0;
	s_end = s;
	while (i < n)
	{
		s_begin = ft_strtrim(s_end, &d);
		if (s_begin != NULL)
		{
			if (i == n - 1)
				d = '\0';
			s_end = ft_strchr(s_begin, d);
			s_len = ft_strlen(s_begin) - ft_strlen(s_end);
			*(ret + i) = ft_strndup(s_begin, s_len);
			free(s_begin);
			if (*(ret + i) == NULL)
			{
				free_strings(ret, i);
				return ;
			}
		}
		i++;
	}
	*(ret + n) = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	n_strings;

	printf("input_begin: s=%s & d=%c\n", s, c);
	n_strings = count_strings((char*)s, c);
	result = malloc((n_strings + 1) * sizeof(char*));
	if (result == NULL)
		return (NULL);
	cpy_strings((char*)s, n_strings, c, result);
	printf("input_end: s=%s & d=%c\n", s, c);
	return (result);
}
