/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panesico <panesico@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:27:20 by panesico          #+#    #+#             */
/*   Updated: 2024/03/06 23:29:31 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sa(t_stc *stc, int boole)
{
	t_lista	*swap;
	t_lista	*swap2;

	swap = stc->hash[0];
	swap2 = swap->next;
	swap2 = swap2->next;
	stc->hash[0] = stc->hash[0]->next;
	stc->hash[0]->next = swap;
	swap->next = swap2;
	if (boole)
	{
		stc->final_moves++;
		ft_printf("sa\n");
	}
}

void	ft_sb(t_stc *stc, int boole)
{
	t_lista	*swap;
	t_lista	*swap2;

	swap = stc->hash[1];
	swap2 = swap->next;
	swap2 = swap2->next;
	stc->hash[1] = stc->hash[1]->next;
	stc->hash[1]->next = swap;
	swap->next = swap2;
	if (boole)
	{
		stc->final_moves++;
		ft_printf("sb\n");
	}
}

void	ft_ss(t_stc *stc)
{
	ft_sa(stc, 0);
	ft_sb(stc, 0);
	stc->final_moves++;
	ft_printf("ss\n");
}

void	ft_pa(t_stc *stc)
{
	t_lista	*swap;
	t_lista	*swap2;

	swap = stc->hash[1];
	stc->hash[1] = stc->hash[1]->next;
	swap2 = stc->hash[0];
	stc->hash[0] = swap;
	stc->hash[0]->next = swap2;
	stc->a_s++;
	stc->b_s--;
	stc->final_moves++;
	ft_printf("pa\n");
}

void	ft_pb(t_stc *stc)
{
	t_lista	*swap;
	t_lista	*swap2;

	swap = stc->hash[0];
	stc->hash[0] = stc->hash[0]->next;
	swap2 = stc->hash[1];
	stc->hash[1] = swap;
	stc->hash[1]->next = swap2;
	stc->a_s--;
	stc->b_s++;
	stc->final_moves++;
	ft_printf("pb\n");
}

void	ft_ra(t_stc *stc, int boole)
{
	t_lista	*head;
	t_lista	*swap;

	swap = stc->hash[0];
	stc->hash[0] = stc->hash[0]->next;
	head = stc->hash[0];
	while (head->next)
		head = head->next;
	head->next = swap;
	swap->next = 0;
	stc->fna = swap;
	if (boole)
	{
		ft_printf("ra\n");
		stc->final_moves++;
	}
}

void	ft_rb(t_stc *stc, int boole)
{
	t_lista	*head;
	t_lista	*swap;

	swap = stc->hash[1];
	stc->hash[1] = stc->hash[1]->next;
	head = stc->hash[1];
	while (head->next)
		head = head->next;
	head->next = swap;
	swap->next = 0;
	if (boole)
	{
		ft_printf("rb\n");
		stc->final_moves++;
	}
}

void	ft_rr(t_stc *stc)
{
	ft_ra(stc, 0);
	ft_rb(stc, 0);
	stc->final_moves++;
	ft_printf("rr\n");
}

void	ft_rra(t_stc *stc, int boole)
{
	t_lista	*head;
	t_lista	*head2;
	t_lista	*swap;

	head = stc->hash[0];
	head2 = stc->hash[0];
	while (head2->next)
	{
		head2 = head2->next;
		if (head2->next)
			head = head->next;
	}
	swap = stc->hash[0];
	head->next = 0;
	stc->hash[0] = head2;
	head2->next = swap;
	stc->fna = swap;
	if (boole)
	{
		ft_printf("rra\n");
		stc->final_moves++;
	}
}

void	ft_rrb(t_stc *stc, int boole)
{
	t_lista	*head;
	t_lista	*head2;
	t_lista	*swap;

	head = stc->hash[1];
	head2 = stc->hash[1];
	while (head2->next)
	{
		head2 = head2->next;
		if (head2->next)
			head = head->next;
	}
	swap = stc->hash[1];
	head->next = 0;
	stc->hash[1] = head2;
	head2->next = swap;
	if (boole)
	{
		ft_printf("rrb\n");
		stc->final_moves++;
	}
}

void	ft_rrr(t_stc *stc)
{
	ft_rra(stc, 0);
	ft_rrb(stc, 0);
	stc->final_moves++;
	ft_printf("rrr\n");
}