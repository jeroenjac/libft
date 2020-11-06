/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 11:48:37 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/11/06 16:49:03 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memset(void *pt, int c, size_t len);
void	*ft_bzero(void *pt, size_t len);
void	*ft_memcpy(void *dst, void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);

#endif
