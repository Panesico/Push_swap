/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:38:26 by jorgfern          #+#    #+#             */
/*   Updated: 2024/03/06 23:29:31 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_check_if_num_split(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '-' || str[i][j] == '+')
			++j;
		while (str[i][j])
			if (!ft_isdigit(str[i][j++]))
				return (0);
		++i;
	}
	return (1);
}

int	ft_check_if_num_argv(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			++j;
		while (argv[i][j])
			if (!ft_isdigit(argv[i][j++]))
				return (0);
		i++;
	}
	return (1);
}

int	ft_validate_if_dup(t_stc *stc)
{
	int	i;
	int	j;
	int	to_find;

	i = 0;
	while (i < stc->tba_s)
	{
		to_find = stc->tb_a[i];
		j = -1;
		while (++j < stc->tba_s - 1)
			if (to_find == stc->tb_a[j] && i != j)
				return (0);
		i++;
	}
	return (1);
}

int	ft_final_validator(t_stc *stc)
{
	t_lista	*head;
	int		min;

	min = -2147483647;
	head = stc->hash[0];
	while (head)
	{
		if (min < head->content)
			min = head->content;
		else
			return (0);
		head = head->next;
	}
	return (1);
}

void	ft_max_finder_list(t_stc *stc, int half)
{
	int		i;
	t_lista	*head;

	i = 1;
	stc->max_num = -2147483647;
	head = stc->hash[0];
	while (head)
	{
		if (stc->max_num < head->content)
		{
			stc->max_num = head->content;
			stc->max_num_pos = i;
		}
		head = head->next;
		i++;
	}
	if (stc->max_num_pos > half)
		stc->max_num_pos = stc->max_num_pos - stc->a_s;
}

void	ft_min_finder_list(t_stc *stc, int half)
{
	int		i;
	t_lista	*head;

	i = 0;
	stc->min = 2147483647;
	head = stc->hash[0];
	while (head)
	{
		if (stc->min > head->content)
		{
			stc->min = head->content;
			stc->min_pos = i;
		}
		head = head->next;
		i++;
	}
	if (stc->max_num_pos > half)
		stc->max_num_pos = stc->max_num_pos - stc->a_s;
}

void	ft_final_sort(t_stc *stc, int boole)
{
	int		i;
	int		half;
	int		*tmp;
	t_lista	*head;

	half = stc->a_s / 2;
	ft_max_finder_list(stc, half);
	i = 0;
	head = stc->hash[0];
	if (boole)
		tmp = stc->tmp;
	else
		tmp = stc->tmp2;
	while (head)
	{
		if (stc->min == head->content)
		{
			tmp[0] = i;
			break ;
		}
		head = head->next;
		i++;
	}
	if (i > half)
		tmp[0] = tmp[0] - stc->a_s;
	if (boole)
		ft_move_set_finder(stc, ft_moves_finder(stc));
}
