/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:38:39 by jorgfern          #+#    #+#             */
/*   Updated: 2023/05/04 01:22:45 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list		arglist;
	int			print_len;
	int			i;

	va_start(arglist, str);
	print_len = 0;
	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
			print_len += ft_convert_printf(str[++i], arglist);
		else
			print_len += ft_putchar_fd_printf(str[i], 1);
		i++;
	}
	va_end(arglist);
	return (print_len);
}
