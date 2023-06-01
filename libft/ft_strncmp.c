/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:05:46 by jorgfern          #+#    #+#             */
/*   Updated: 2023/04/25 21:12:20 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char)(s1[i]) == (unsigned char)(s2[i]))
			i++;
		else
		{
			if ((unsigned char)(s1[i]) < (unsigned char)(s2[i]))
				return (-1);
			if ((unsigned char)(s1[i]) > (unsigned char)(s2[i]))
				return (1);
		}
	}
	return (0);
}
