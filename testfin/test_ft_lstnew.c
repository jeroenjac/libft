/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_lstnew.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 15:27:27 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/12/03 15:47:22 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "inittest.c"
#include "../libft.h"
#include <string.h>

int		main(int argc, char **argv)
{
	int		ft;

	printf("prog: %s\n", argv[0]);
	ft = inittest(argc, "ft_lstnew");

	if (ft == 3)
	{
		t_list	*test1;
		char	*testcontent;
		
		testcontent = strdup("Hello");

		test1 = ft_lstnew(testcontent);
		printf("list el 1: %s", test1->content);
		//printf("list el 2: %s", test1->next);
		
	}
}
