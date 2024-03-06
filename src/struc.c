/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lista.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panesico <panesico@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:22:42 by panesico          #+#    #+#             */
/*   Updated: 2023/05/27 19:06:14 by panesico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_lista	*ft_new_node(int content)
{
	t_lista	*list;

	list = (t_lista *)malloc(sizeof(t_lista));
	if (!list)
		return (0);
	list->content = content;
	list->next = 0;
	return (list);
}

void	ft_free_lista(t_lista **lista)
{
	t_lista *to_del;

	while (*lista)
	{
		to_del = *lista;
		*lista = (*lista)->next;
		if (to_del)
			free(to_del);
	}
	free(lista);
}

void	ft_free_all(t_stc *stc)
{
	if (stc->tmp)
		free(stc->tmp);
	if (stc->tmp2)
		free(stc->tmp2);
	if (stc->hash)
		ft_free_lista(stc->hash);
	free(stc->tb_a);
	free(stc);
}

t_lista	**ft_fill_hash(t_lista **hash, int *tab, int size, t_lista **last)
{
	int i;
	t_lista	*head;

	i = 0;
	hash[0] = ft_new_node(tab[i]);
	if (!hash[0])
		return (ft_free_lista(hash), NULL);
	i++;
	head = hash[0];
	while (i < size)
	{
		head->next = ft_new_node(tab[i]);
		if (!head->next)
			return (ft_free_lista(hash), NULL);
		if (head->next)
			head = head->next;
		i++;
	}
	*last = head;
	hash[1] = 0;
	return (hash);
}

t_lista	**ft_create_hash(int *tab, int size, t_lista **last)
{
	t_lista	**hash;

	hash = (t_lista **)malloc(sizeof(t_lista *) * 2);
	hash = ft_fill_hash(hash, tab, size, last);
	if (!hash)
		return (0);
	return (hash);
}

void	ft_declare_stc(t_stc *stc, int *lis, int lis_size)
{
	stc->b_s = 0;
	stc->lis = lis;
	stc->l_s = lis_size;
	stc->tmp[0] = 0;
	stc->tmp[1] = 0;
	stc->tmp2[0] = 0;
	stc->tmp2[1] = 0;
	stc->ward = 0;
	stc->max = 0;
	stc->min = 2147483647;
	stc->max_num = -2147483647;
	stc->min_pos = 0;
	stc->max_num_pos = 0;
	stc->final_moves = 0;
}

t_stc	*ft_create_stc(int *tab, int size, int *lis, int lis_size)
{
	t_stc	*stc;

	stc = (t_stc *)malloc(sizeof(t_stc));
	if (!stc)
		return (0);
	stc->tb_a = tab;
	stc->tba_s = size;
	stc->a_s = size;
	stc->hash = ft_create_hash(tab, size, &stc->fna);
	stc->tmp = (int *)malloc(sizeof(int) * 2);
	stc->tmp2 = (int *)malloc(sizeof(int) * 2);
	ft_declare_stc(stc, lis, lis_size);
	if (!stc->hash || !stc->tmp || !stc->tmp2)
		return (ft_free_all(stc), NULL);
	if (!ft_validate_if_dup(stc))
	{
		ft_printf("error");
		ft_free_all(stc);
		exit(0);
	}
	return (stc);
}

