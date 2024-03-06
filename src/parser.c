/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:38:26 by jorgfern          #+#    #+#             */
/*   Updated: 2024/03/06 23:33:04 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_error(int error)
{
	ft_printf("Error\n");
	exit(error);
}

int	*ft_parser1(char **argv, int *size)
{
	char	**str;
	int		*tab;
	int		i;
	long	long_num;

	str = ft_split(argv[1], ' ');
	if (!ft_check_if_num_split(str))
		ft_error(1);
	while (str[*size])
		*size += 1;
	tab = (int *)malloc(sizeof(int) * (*size));
	if (!tab)
		ft_error(1);
	i = 0;
	while (str[i])
	{
		long_num = ft_atol(str[i]);
		if (long_num > 2147483647 || long_num < -2147483648)
			ft_error(1);
		tab[i] = ft_atoi(str[i]);
		i++;
	}
	ft_free_split(str);
	return (tab);
}

int	*ft_parser2(int argc, char **argv, int *size)
{
	int		*tab;
	int		i;
	long	long_num;

	if (!ft_check_if_num_argv(argc, argv))
		return (0);
	*size = argc - 1;
	tab = (int *)malloc(sizeof(int) * *size);
	i = 1;
	while (i <= *size)
	{
		long_num = ft_atol(argv[i]);
		if (long_num > 2147483647 || long_num < -2147483648)
			ft_error(1);
		tab[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (tab);
}

int	*ft_parser(int argc, char **argv, int *size)
{
	int *tab;

	tab = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
		tab = ft_parser1(argv, size);
	else
		tab = ft_parser2(argc, argv, size);
	return (tab);
}