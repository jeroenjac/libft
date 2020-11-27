/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 23:27:14 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/26 18:38:25 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** APPROACH
** 1. Get length of input string
** 2. Assuming len_output == len_input, malloc for output.
**		Return NULL if fail.
** 3. Make sure the function is executed on every element in -> out
**		Conditional? Or just pass it, for the f to use or not?
**
** ERROR CATCHING FOR UNSUITABLE F, *s, INT? (by thf function f??)
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*output;

	if (s == NULL)
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
