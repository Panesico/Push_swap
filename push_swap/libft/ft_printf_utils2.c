/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:38:42 by jorgfern          #+#    #+#             */
/*   Updated: 2023/05/03 21:00:32 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putbase_printf(unsigned int num, char *base)
{
	unsigned int	len;
	unsigned int	base_len;

	base_len = ft_strlen_printf(base);
	len = 0;
	if (num >= base_len)
		len += ft_putbase_printf(num / base_len, base);
	ft_putchar_fd_printf(base[num % base_len], 1);
	len++;
	return (len);
}

int	ft_putbasel_printf(unsigned long long num, char *base)
{
	unsigned int	len;
	unsigned int	base_len;

	base_len = ft_strlen_printf(base);
	len = 0;
	if (num >= base_len)
		len += ft_putbasel_printf(num / base_len, base);
	ft_putchar_fd_printf(base[num % base_len], 1);
	len++;
	return (len);
}

int	ft_putptr_printf(unsigned long long num, char *base)
{
	unsigned int	len;

	len = 0;
	len += ft_putstr_fd_printf("0x", 1);
	len += ft_putbasel_printf(num, base);
	return (len);
}

int	ft_convert_printf(char c, va_list arglist)
{
	unsigned int		len;

	len = 0;
	if (c == 'd' || c == 'i')
		len = ft_print_itoa_printf(va_arg(arglist, int));
	else if (c == 'u')
		len = ft_putunbr_fd_printf(va_arg(arglist, unsigned int), 1);
	else if (c == 'c')
		len = ft_putchar_fd_printf(va_arg(arglist, int), 1);
	else if (c == 's')
		len = ft_putstr_fd_printf(va_arg(arglist, char *), 1);
	else if (c == 'x')
		len = ft_putbase_printf(va_arg(arglist, unsigned int),
				"0123456789abcdef");
	else if (c == 'X')
		len = ft_putbase_printf(va_arg(arglist, unsigned int),
				"0123456789ABCDEF");
	else if (c == 'p')
		len = ft_putptr_printf(va_arg(arglist, unsigned long long),
				"0123456789abcdef");
	else if (c == '%')
		len = ft_putchar_fd_printf('%', 1);
	return (len);
}
