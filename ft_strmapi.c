/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 23:27:14 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/12/07 10:53:14 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*output;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	output = malloc((len + 1) * sizeof(char));
	if (output == NULL)
		return (NULL);
	output[len] = '\0';
	len--;
	while (len >= 0)
	{
		output[len] = f(len, s[len]);
		len--;
	}
	return (output);
}
