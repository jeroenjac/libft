/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 20:55:29 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/12 23:22:16 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_isascii(int c)
{
	unsigned int	p;

	p = (unsigned int)c;
	if (p >= 0 && p <= 127)
		return (1);
	else
		return (0);
}
