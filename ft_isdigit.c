/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 13:29:19 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/12/07 10:45:26 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
