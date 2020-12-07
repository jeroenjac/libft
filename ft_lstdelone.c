/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/06 21:53:26 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/12/06 22:36:16 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!(lst == NULL || del == NULL))
	{
		(*del)(lst->content);
		free(lst);
	}
	return ;
}
