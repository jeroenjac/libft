/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/06 22:39:28 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/12/06 23:33:50 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nextdel;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		nextdel = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nextdel;
	}
}
