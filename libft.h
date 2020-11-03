/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 11:48:37 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/03 20:12:56 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memset(void *pt, int c, size_t len);
void	*ft_bzero(void *pt, size_t len);
void	*ft_memcpy(void *dst, void *src, size_t n);
