#include "../include/push_swap.h"

void	ft_sort_3(t_stc *stc)
{
	t_lista	*head;
	t_lista	*head2;

	head = stc->hash[0];
	head2 = head->next;
	if (head->content > head2->content && head2->content > stc->fna->content)
	{
		ft_sa(stc, 1);
		ft_rra(stc, 1);
	}
	if (head2->content > stc->fna->content && head->content < stc->fna->content)
	{
		ft_sa(stc, 1);
		ft_ra(stc, 1);
	}
	if (head->content > head2->content && head->content < stc->fna->content)
		ft_sa(stc, 1);
	if (head2->content < stc->fna->content && head->content > stc->fna->content)
		ft_ra(stc, 1);
	if (head2->content > stc->fna->content && head->content > stc->fna->content)
		ft_rra(stc, 1);
}

void	ft_sort_5(t_stc *stc)
{
	int move_set;

	move_set = 0;
	while (stc->a_s > 3)
		ft_pb(stc);
	ft_sort_3(stc);
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
}