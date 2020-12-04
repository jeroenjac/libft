/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_lstlast.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 18:21:57 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/12/04 18:43:33 by jjacobs       ########   odam.nl         */
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
	ft = inittest(argc, "ft_lstlast");
	
	if (ft == 1)
	{
		t_list	*l;
		t_list	*niks = ((void *)0);
		char	*lastcontent = "Cookie";

		l = ft_lstnew(strdup("h"));
		l->next = ft_lstnew(strdup("a"));
		l->next->next = ft_lstnew(strdup("l"));
		l->next->next->next = ft_lstnew(strdup("l"));
		l->next->next->next->next = ft_lstnew(strdup(lastcontent));

	
		t_list	*print;

		print = ft_lstlast(l);
		printf("Last element (content) == %s? %s\n", lastcontent, print->content);
		if (strcmp(print->content, lastcontent) == 0)
			printf("\t\t\tPASSED\n");
		else
			printf("\t\t\tFAILED\n");
		printf ("Testing for NULL\n");
		print = ft_lstlast(NULL);
		if (print == NULL)
			printf("\t\t\tPASSED\n");
		else
			printf("\t\t\tFAILED\n");
		printf ("Testing for niks ((void *)0)\n");
		print = ft_lstlast(niks);
		if (print == NULL)
			printf("\t\t\tPASSED\n");
		else
			printf("\t\t\tFAILED\n");
	}
}
