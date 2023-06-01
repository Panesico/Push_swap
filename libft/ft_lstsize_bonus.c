/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:05:28 by jorgfern          #+#    #+#             */
/*   Updated: 2023/04/28 20:02:58 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*head;
	size_t	count;

	if (!lst)
		return (0);
	count = 1;
	head = lst->next;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}
