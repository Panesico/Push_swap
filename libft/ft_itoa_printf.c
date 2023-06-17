/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:38:37 by jorgfern          #+#    #+#             */
/*   Updated: 2023/05/04 01:22:21 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_digit_count_printf(long nb)
{
	unsigned int	count;

	count = 0;
	if (!nb)
		count = 1;
	if (nb < 0)
	{
		nb = -nb;
		count++;
	}
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa_printf(int nb)
{
	int				i;
	long			num;
	char			*str;

	num = nb;
	str = (char *)malloc((ft_digit_count_printf(num) + 1) * sizeof(char));
	if (!str)
		return (0);
	str[ft_digit_count_printf(num)] = '\0';
	if (num == 0)
		str[0] = '0';
	i = ft_digit_count_printf(num) - 1;
	if (num < 0)
	{
		num = -num;
		str[0] = '-';
	}
	while (num > 0)
	{
		str[i--] = (num % 10) + 48;
		num /= 10;
	}
	return (str);
}
