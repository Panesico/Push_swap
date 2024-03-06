/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panesico <panesico@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:28:37 by panesico          #+#    #+#             */
/*   Updated: 2024/03/06 23:29:31 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_find_if_between_ends(t_stc *stc, int *tmp, int num, t_lista *head)
{
	if (num > stc->max_num)
		return (*tmp = stc->max_num_pos, 2);
	if (num < stc->min)
		return (*tmp = stc->min_pos, 3);
	if (head->content < num && num < stc->hash[0]->content)
		return (*tmp = 0, 1);
	return (0);
}

int	ft_find_moves_max(t_stc *stc, int *tmp, int num)
{
	if (num > stc->max_num)
		return (tmp[0] = stc->max_num_pos, 1);
	return (0);
}

int	ft_lis_confirm(t_stc *stc, int num)
{
	int	i;

	i = 0;
	while (i < stc->l_s - 1)
	{
		if (stc->lis[i] < num && num < stc->lis[i + 1])
			return (1);
		else
			i++;
	}
	return (0);
}

int	ft_find_moves_a(t_stc *stc, int *tmp, int num, int half)
{
	int		i;
	t_lista	*head;
	t_lista	*head2;

	head = stc->hash[0];
	head2 = stc->hash[0];
	i = 0;
	while (i <= half)
	{
		head = head->next;
		i++;
		if (head2->content < num && num < head->content)
			return (*tmp = i, 1);
		head2 = head2->next;
	}
	while (i < stc->a_s - 1)
	{
		head = head->next;
		i++;
		if (head2->content < num && num < head->content)
			return (*tmp = i - stc->a_s, -1);
		head2 = head2->next;
	}
	if (ft_find_if_between_ends(stc, tmp, num, head))
		return (1);
	return (0);
}
/*
void	ft_find_moves_b(t_stc *stc, int *tmp, int num, int half)
{
	int		i;
	t_lista	*head;
	t_lista	*head2;

	head = stc->hash[0];
	i = 0;
	while (i < half)
	{
		head = head->next;
		if (head2->*content == num)
			tmp[1] = i;
		head2 = head2->next;
		i++;
	}
	while (i < stc->a_s)
	{
		head = head->next;
		if (head2->*content > num && num < head->*content)
			tmp[1] = i - stc->a_s;
		i++;
	}
}
 */

int	ft_compare_nums(t_stc *stc)
{
	int	maxa;
	int	maxb;

	if (stc->tmp[0] <= 0 && stc->tmp[1] >= 0)
		maxa = -stc->tmp[0] + stc->tmp[1];
	else if (stc->tmp[0] >= 0 && stc->tmp[1] <= 0)
		maxa = stc->tmp[0] + -stc->tmp[1];
	else if (stc->tmp[0] <= 0 && stc->tmp[1] <= 0)
		maxa = -stc->tmp[0] + -stc->tmp[1];
	else
		maxa = stc->tmp[0] + stc->tmp[1];
	if (stc->tmp2[0] <= 0 && stc->tmp2[1] >= 0)
		maxb = -stc->tmp2[0] + stc->tmp2[1];
	else if (stc->tmp2[0] >= 0 && stc->tmp2[1] <= 0)
		maxb = stc->tmp2[0] + -stc->tmp2[1];
	else if (stc->tmp2[0] <= 0 && stc->tmp2[1] <= 0)
		maxb = -stc->tmp2[0] + -stc->tmp2[1];
	else
		maxb = stc->tmp2[0] + stc->tmp2[1];
	if (maxb < maxa)
		return (1);
	return (0);
}

void	ft_change_tmp_value(t_stc *stc)
{
	stc->tmp[0] = stc->tmp2[0];
	stc->tmp[1] = stc->tmp2[1];
}

void	ft_find_best_move(t_stc *stc)
{
	int		i;
	t_lista	*head;

	ft_max_finder_list(stc, stc->a_s / 2);
	ft_min_finder_list(stc, stc->a_s / 2);
	ft_find_moves_a(stc, stc->tmp, stc->hash[1]->content, stc->a_s / 2);
	stc->tmp[1] = 0;
	head = stc->hash[1];
	if (head)
		head = head->next;
	i = 1;
	while (head)
	{
		ft_find_moves_a(stc, &stc->tmp2[0], head->content, stc->a_s / 2);
		if (i <= stc->b_s / 2)
			stc->tmp2[1] = i;
		else
			stc->tmp2[1] = i - stc->b_s;
		if (ft_compare_nums(stc))
			ft_change_tmp_value(stc);
		head = head->next;
		i++;
	}
}

int	ft_moves_finder(t_stc *stc)
{
	if (!stc->tmp[0] && !stc->tmp[1])
		return (0);
	else if (stc->tmp[0] >= 0 && stc->tmp[1] >= 0)
		return (1);
	else if (stc->tmp[0] <= 0 && stc->tmp[1] <= 0)
		return (-1);
	else if (stc->tmp[0] <= 0 && stc->tmp[1] >= 0)
		return (2);
	else
		return (-2);
}

int	ft_b_more_than_2(t_stc *stc)
{
	if (stc->hash[1])
		if (stc->hash[1]->next)
			if (stc->hash[1]->next->next)
				return (1);
	return (0);
}

void	ft_move_cheese(t_stc *stc)
{
	t_lista	*head;
	t_lista	*head_n;

	head = 0;
	head_n = 0;
	if (ft_b_more_than_2(stc))
	{
		head = stc->hash[1];
		head_n = head->next;
		if (head->content < head_n->content
			&& head_n->content < head_n->next->content)
			ft_sb(stc, 1);
	}
}

int	ft_solver(t_stc *stc)
{
	int move_set;

	ft_lis(stc);
	ft_lis_to_b(stc);
	while (stc->hash[1])
	{
		ft_find_best_move(stc);
		move_set = ft_moves_finder(stc);
		if (!move_set)
		{
			ft_pa(stc);
		}
		else
		{
			ft_move_set_finder(stc, move_set);
			ft_pa(stc);
		}
	}
	if (!ft_final_validator(stc))
		ft_final_sort(stc, 1);
	return (1);
}