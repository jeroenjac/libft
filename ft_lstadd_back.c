/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 18:18:08 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/12/04 19:18:46 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == NULL)
		*lst = new;
	else if ((*lst)->next == NULL)
		(*lst)->next = new;
	else
		ft_lstadd_back(&(*lst)->next, new);
}
