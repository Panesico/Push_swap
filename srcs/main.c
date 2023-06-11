/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panesico <panesico@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:32:02 by panesico          #+#    #+#             */
/*   Updated: 2023/05/28 04:54:39 by panesico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_stack(t_stc *stc)
{
	t_lista *head;
	t_lista	*head2;

	head = stc->hash[0];
	head2 = 0;
	if (stc->hash[1])
		head2 = stc->hash[1];
	while (head)
	{
		ft_printf("%d\t-\t", head->content);
		head = head->next;
			if (head2)
			{
				ft_printf("%d\n", head2->content);
				head2 = head->next;
			}
			else
				ft_printf("\n");
	}
}

void	ft_print_stack_a(t_stc *stc)
{
	t_lista *head;

	head = 0;
	if (stc->hash[0])
		head = stc->hash[0];;
	while (head)
	{
		ft_printf("%d ", head->content);
		head = head->next;
	}
	ft_printf("\n");
}

void	ft_print_stack_b(t_stc *stc)
{
	t_lista *head;

	head = 0;
	if (stc->hash[1])
		head = stc->hash[1];
	while (head)
	{
		ft_printf("%d ", head->content);
		head = head->next;
	}
	ft_printf("\n");
}

void	ft_print_all(t_stc *stc)
{
	int i;
	t_lista *head;

	ft_printf("%d  --  a_s\n\n", stc->a_s);
	ft_printf("%d  --  b_s\n\n", stc->b_s);
	ft_printf("%p  --  lis\n\n", stc->lis);
	i = -1;
	while (++i < stc->l_s)
		ft_printf("%d  --  lis[%d]\n", stc->lis[i], i);
	ft_printf("%d  --  l_s\n\n", stc->l_s);
	i = -1;
	while (++i < stc->tba_s)
		ft_printf("%d  --  tb_a[%d]\n", stc->tb_a[i], i);
	ft_printf("%d  --  tba_s\n\n", stc->tba_s);
	i = -1;
	while (++i < 2)
		ft_printf("%d  --  tmp[%d]\n", stc->tmp[i], i);
	i = -1;
	while (++i < 2)
		ft_printf("%d  --  tmp2[%d]\n", stc->tmp2[i], i);
	head = stc->hash[0];
	while (head)
	{
		ft_printf("%d, ", head->content);
		head = head->next;
	}
	ft_printf("    --    stack A");
}

int	main(int argc, char **argv)
{
	int		size;
	int 	*tab;
	t_stc	*stc;

	if (argc < 2)
		exit(0);
	size = 0;
	tab = ft_parser(argc, argv, &size);
	if (!tab)
	{
		ft_printf("Error");
		exit(0);
	}
	stc = ft_create_stc(tab, size, NULL, 0);
	printf ("HOla SOY A_SIZE:  %d\n", stc->a_s);
	if (stc->a_s == 1 || ft_final_validator(stc))
	{
		ft_free_all(stc);
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
	if (ft_final_validator(stc))
		ft_printf("sorted");
	ft_printf("!! %d movimientos!!\n", stc->final_moves);
	ft_free_all(stc);
}