/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_lstsize.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 17:49:16 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/12/04 18:21:36 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include "inittest.c"
#include <string.h>

int		main(int argc, char **argv)
{
	int		ft;
	printf("prog: %s\n", argv[0]);
	ft = inittest(argc, "ft_lstsize");
	
	if (ft == 3)
	{
	t_list	*l;
	t_list	*niks = ((void *)0);

	l = ft_lstnew(strdup("h"));
	l->next = ft_lstnew(strdup("a"));
	l->next->next = ft_lstnew(strdup("l"));
	l->next->next->next = ft_lstnew(strdup("l"));
	l->next->next->next->next = ft_lstnew(strdup("o"));

		int		size;
	
		size = ft_lstsize(NULL);
		printf("Size of list = %i\n", size);
		if (size != 0)
			printf("\t\t\tFAILED\n");
		else
			printf("\t\t\tSUCCES\n");
		size = ft_lstsize(niks);
		printf("Size of list = %i\n", size);
		if (size != 0)
			printf("\t\t\tFAILED\n");
		else
			printf("\t\t\tSUCCES\n");
		size = ft_lstsize(l);
		printf("Size of list = %i\n", size);
		if (size != 5)
			printf("\t\t\tFAILED\n");
		else
			printf("\t\t\tSUCCES\n");
	}
}
