/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:30:52 by jorgfern          #+#    #+#             */
/*   Updated: 2023/06/07 21:30:52 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(const char *str)
{
	int		i;
	int		negative;
	double	num;
	double	num2;

	i = 0;
	negative = 0;
	num = 0;
	num2 = 0;
	while (ft_isspace(str[i]))
		i++;
	ft_if_negative(str, &negative, &i);
	while (str[i] >= '0' && str[i] <= '9')
		num = (num * 10) + (str[i++] - 48);
	if (str[i] == '.')
		i++;
	num2 = ft_recursive_get_decimal(str, i, num2);
	num += num2;
	if (negative)
		num *= -1;
	return (num);
}
