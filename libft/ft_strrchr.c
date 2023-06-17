/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:05:48 by jorgfern          #+#    #+#             */
/*   Updated: 2023/04/25 20:53:32 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	*ptr;

	i = -1;
	ptr = 0;
	while (str[++i])
	{
		if (str[i] == (char)c)
			ptr = &((char *)str)[i];
	}
	if (str[i] == (char)c)
		ptr = &((char *)str)[i];
	if (!c)
		ptr = &((char *)str)[i];
	return (ptr);
}
