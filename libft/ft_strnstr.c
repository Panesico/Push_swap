/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:05:47 by jorgfern          #+#    #+#             */
/*   Updated: 2023/04/26 15:12:21 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	s2_len;

	if (!(*s2) || s1 == s2)
		return ((char *)s1);
	s2_len = ft_strlen(s2);
	while (*s1 && s2_len <= n)
	{
		if (!(ft_strncmp((char *)s1, (char *)s2, s2_len)))
			return ((char *)s1);
		s1++;
		n--;
	}
	return (0);
}
