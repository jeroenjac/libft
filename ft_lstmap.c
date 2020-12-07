/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/06 23:41:10 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/12/07 01:05:28 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*new;
	t_list	*lstcpy;

	ret = NULL;
	lstcpy = lst;
	while (lstcpy != NULL)
	{
		new = ft_lstnew((*f)(lstcpy->content));
		if (new == NULL)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		ft_lstadd_back(&ret, new);
		lstcpy = lstcpy->next;
	}
	return (ret);
}

/*
** Method re-uses other created lst_functions.
** Also, it leaves the pointer to the initial element (e.g. 'lst') unchanged.
** (I would have to show this in a test, still)
** What's not clear for me at this moment. Wouldn't this also work by;
**	declaring **ret (instead of *ret); because it's also arg for add_back/clear
**	initializing *ret & ret = NULL
**	updating '&ret' to 'ret' in below code
**	returning (*ret, e.g. 1x dereference) instead of ret
*/
