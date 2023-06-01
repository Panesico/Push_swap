/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:05:29 by jorgfern          #+#    #+#             */
/*   Updated: 2023/05/10 17:53:48 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	char			*s2;
	char			c2;

	s2 = (char *)s;
	c2 = (char)c;
	i = -1;
	while (++i < n)
	{
		if (*s2 == c2)
			return (s2);
		s2++;
	}
	return (0);
}
