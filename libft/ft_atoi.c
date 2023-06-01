/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:05:03 by jorgfern          #+#    #+#             */
/*   Updated: 2023/04/26 15:16:16 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	negative;
	int	num;

	i = 0;
	negative = 0;
	num = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			negative++;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = (num * 10) + (str[i++] - 48);
	if (negative)
		num *= -1;
	return (num);
}
