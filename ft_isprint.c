/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 21:03:56 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/12 21:12:40 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprint(int c)
{
	unsigned int p;

	p = (unsigned int)c;
	if (p >= 32 && p <= 126)
		return (1);
	else
		return (0);
}
