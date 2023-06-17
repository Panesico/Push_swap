/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:05:36 by jorgfern          #+#    #+#             */
/*   Updated: 2023/04/28 17:59:35 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_arraylen(char *str, char delimiter)
{
	size_t	i;
	size_t	del_count;

	i = 0;
	del_count = 0;
	while (str[i])
	{
		if (str[i] != delimiter)
		{
			del_count++;
			while (str[i] && str[i] != delimiter)
				i++;
		}
		else
			i++;
	}
	return (del_count);
}

static	size_t	ft_wordlen(char *str, char del, size_t i)
{
	size_t	len;

	len = 0;
	while (str[i] != del && str[i])
	{
		len++;
		i++;
	}
	return (len);
}

static	void	ft_free_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	int		array_len;
	int		word_len;
	char	**array;

	array_len = ft_arraylen((char *)s, c);
	array = (char **)malloc((array_len + 1) * sizeof(char *));
	if (!array)
		return (0);
	i = 0;
	k = 0;
	while (i < array_len && s[k])
	{
		while (s[k] == c)
			k++;
		word_len = ft_wordlen((char *)s, c, k);
		array[i] = ft_substr(s, k, word_len);
		if (!array[i])
			return (ft_free_array(array), NULL);
		i++;
		k += word_len;
	}
	array[i] = 0;
	return (array);
}
