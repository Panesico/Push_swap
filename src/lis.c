/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:38:26 by jorgfern          #+#    #+#             */
/*   Updated: 2024/03/06 23:29:31 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:36:40 by panesico          #+#    #+#             */
/*   Updated: 2023/06/13 20:56:29 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_fm_lis_loop(t_stc *stc, int j, int ward2, int count)
{
	while (j < stc->tba_s - 1)
	{
		if (stc->tb_a[ward2] < stc->tb_a[j + 1])
		{
			count++;
			ward2 = j + 1;
		}
		j++;
	}
	return (count);
}

void	ft_find_max_lis(t_stc *stc)
{
	int	i;
	int	j;
	int	ward2;
	int	count;

	i = 0;
	count = 0;
	while (i < stc->tba_s - 1)
	{
		j = i;
		ward2 = j;
		count = 1;
		count = ft_fm_lis_loop(stc, j, ward2, count);
		if (stc->max < count)
		{
			stc->ward = i;
			stc->max = count;
		}
		i++;
	}
}

void	ft_fill_lis(t_stc *stc)
{
	int	i;
	int	ward;

	i = 1;
	stc->lis[0] = stc->tb_a[stc->ward];
	ward = stc->ward;
	while (i < stc->max && stc->ward < stc->tba_s)
	{
		if (stc->tb_a[ward] < stc->tb_a[stc->ward + 1])
		{
			stc->lis[i] = stc->tb_a[stc->ward + 1];
			ward = stc->ward + 1;
			i++;
			stc->ward++;
		}
		else
			stc->ward++;
	}
}

int	ft_lis(t_stc *stc)
{
	ft_find_max_lis(stc);
	stc->lis = (int *)malloc(sizeof(int) * stc->max);
	if (!stc->lis)
		return (0);
	stc->l_s = stc->max;
	ft_fill_lis(stc);
	return (1);
}

void	ft_lis_to_b(t_stc *stc)
{
	int	i;
	int	j;
	int	boole;
	int	max;

	j = 0;
	boole = 1;
	max = stc->lis[stc->l_s - 1];
	i = -1;
	ft_max_finder_list(stc, stc->tba_s);
	while (++i < stc->tba_s)
	{
		if (boole)
		{
			if (stc->hash[0]->content != stc->lis[0])
			{
				if (stc->hash[0]->content > max)
				{
					max = stc->hash[0]->content;
					ft_ra(stc, 1);
				}
				else
					ft_pb(stc);
			}
			else
				boole = 0;
		}
		else
		{
			if (j < stc->l_s && stc->hash[0]->content == stc->lis[j])
			{
				ft_ra(stc, 1);
				j++;
			}
			else
				ft_pb(stc);
		}
	}
}
