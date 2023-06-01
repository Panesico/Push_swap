/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panesico <panesico@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:03:31 by panesico          #+#    #+#             */
/*   Updated: 2023/05/09 20:03:31 by panesico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc_gnl(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(const char *str, int c)
{
	size_t	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
	}
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
		s1 = (char *)ft_calloc_gnl(1, sizeof(char));
	if (!s1 || !s2)
		return (0);
	str = ft_calloc_gnl(((ft_strlen_gnl(s1) + ft_strlen_gnl(s2)) + 1), sizeof(char));
	if (!str)
		return (0);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = 0;
	return (free(s1), str);
}
