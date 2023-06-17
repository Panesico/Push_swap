/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:05:39 by jorgfern          #+#    #+#             */
/*   Updated: 2023/04/25 18:05:39 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*s;
	size_t	i;
	size_t	src_len;
	size_t	dst_len;
	size_t	res;

	s = (char *)src;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(s);
	res = 0;
	i = 0;
	if (size > dst_len)
		res = src_len + dst_len;
	else
		res = src_len + size;
	while (s[i] && (dst_len + 1) < size)
	{
		dst[dst_len] = s[i];
		dst_len++;
		i++;
	}
	dst[dst_len] = 0;
	return (res);
}
