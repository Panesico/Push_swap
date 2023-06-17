/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:02:32 by jorgfern          #+#    #+#             */
/*   Updated: 2023/04/28 20:45:21 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*first_node;

	if (!lst)
		return (0);
	first_node = (t_list *)malloc(sizeof(t_list));
	if (!first_node)
		return (0);
	first_node->content = f(lst -> content);
	node = first_node;
	while (lst->next)
	{
		lst = lst -> next;
		node -> next = (t_list *)malloc(sizeof(t_list));
		if (!node->next)
		{
			ft_lstclear(&first_node, del);
			return (0);
		}
		node = node -> next;
		node -> content = f(lst -> content);
	}
	node -> next = 0;
	return (first_node);
}
