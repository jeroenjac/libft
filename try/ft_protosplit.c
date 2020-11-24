/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 16:28:19 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/17 19:07:51 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

	/*
** Approach
** 1. Find # of strings, by counting c in *s (~strchr).
** 2. Malloc **result, based on this. Include space for term. NULL ptr. Calloc?
** 3. While loop find c0 (start at 0) and c1 in s.
** 4. Take substring (~ft_substr) and put *subres in **result.
** 5. Do this until loop find '\0' (end of string s)
** 6. Add NULL
*/

char	**ft_split(char const *s, char c)
{
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
