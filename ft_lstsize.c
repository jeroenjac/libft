/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 16:05:57 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/12/04 18:17:23 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int size;

	if (lst == NULL)
		return (0);
	size = 1;
	if (lst->next != NULL)
		size = size + ft_lstsize(lst->next);
	return (size);
}

/*
** If content = NULL. Done return (size = 0).
** If content != NULL. size++
*/
