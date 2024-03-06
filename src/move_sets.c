/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sets.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panesico <panesico@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:04:43 by panesico          #+#    #+#             */
/*   Updated: 2024/03/06 23:29:31 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_move_set_1(t_stc *stc)
{
	while (stc->tmp[0] && stc->tmp[1])
	{
		ft_rr(stc);
		stc->tmp[0]--;
		stc->tmp[1]--;
	}
	while (stc->tmp[0])
	{
		ft_ra(stc, 1);
		stc->tmp[0]--;
	}
	while (stc->tmp[1])
	{
		ft_rb(stc, 1);
		stc->tmp[1]--;
	}
}

void	ft_move_set_1_2(t_stc *stc)
{
	while (stc->tmp[0] && stc->tmp[1])
	{
		ft_rrr(stc);
		stc->tmp[0]++;
		stc->tmp[1]++;
	}
	while (stc->tmp[0])
	{
		ft_rra(stc, 1);
		stc->tmp[0]++;
	}
	while (stc->tmp[1])
	{
		ft_rrb(stc, 1);
		stc->tmp[1]++;
	}
}

void	ft_move_set_2(t_stc *stc)
{
	while (stc->tmp[0])
	{
		ft_rra(stc, 1);
		stc->tmp[0]++;
	}
	while (stc->tmp[1])
	{
		ft_rb(stc, 1);
		stc->tmp[1]--;
	}
}

void	ft_move_set_2_2(t_stc *stc)
{
	while (stc->tmp[0])
	{
		ft_ra(stc, 1);
		stc->tmp[0]--;
	}
	while (stc->tmp[1])
	{
		ft_rrb(stc, 1);
		stc->tmp[1]++;
	}
}

void	ft_move_set_finder(t_stc *stc, int move_set)
{
	if (move_set == 1)
		ft_move_set_1(stc);
	else if (move_set == -1)
		ft_move_set_1_2(stc);
	else if (move_set == 2)
		ft_move_set_2(stc);
	else
		ft_move_set_2_2(stc);
}