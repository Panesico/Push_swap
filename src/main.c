/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:32:02 by panesico          #+#    #+#             */
/*   Updated: 2023/06/13 21:12:53 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_main2(t_stc *stc)
{
	if (stc->a_s == 1 || ft_final_validator(stc))
	{
		exit(0);
	}
	if (stc->a_s == 2)
		ft_ra(stc, 1);
	else if (stc->a_s == 3)
		ft_sort_3(stc);
	else if(stc->a_s > 3 && stc->a_s < 7)
		ft_sort_5(stc);
	else
		ft_solver(stc);
}

int	main(int argc, char **argv)
{
	int		size;
	int 	*tab;
	t_stc	*stc;

	if (argc < 2)
		exit(1);
	size = 0;
	tab = ft_parser(argc, argv, &size);
	if (!tab)
	{
		ft_printf("Error");
		exit(1);
	}
	stc = ft_create_stc(tab, size, NULL, 0);
	ft_main2(stc);
}