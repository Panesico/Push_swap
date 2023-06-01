/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panesico <panesico@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:01:54 by panesico          #+#    #+#             */
/*   Updated: 2023/05/09 20:01:54 by panesico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_nlsplit_gnl(char *buffer)
{
	int		i;
	int		j;
	char	*temp;

	if (!buffer)
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i++])
		return (free(buffer), NULL);
	temp = ft_calloc_gnl((ft_strlen_gnl(buffer) - i + 1), sizeof(char));
	if (!temp)
		return (0);
	j = 0;
	while (buffer[i])
		temp[j++] = buffer[i++];
	return (free(buffer), temp);
}

char	*ft_next_line_gnl(char *buffer)
{
	int		i;
	char	*temp;

	if (!buffer[0])
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	temp = ft_calloc_gnl((i + 2), sizeof(char));
	if (!temp)
		return (0);
	i = -1;
	while (buffer[++i] && buffer[i] != '\n')
		temp[i] = buffer[i];
	if (buffer[i] == '\n')
		temp[i] = buffer[i];
	return (temp);
}

char	*ft_read_gnl(char *buffer, int fd)
{
	char		*str;
	ssize_t		last_line_boole;

	str = (char *)ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	if (!str)
		return (0);
	last_line_boole = 1;
	while (!ft_strchr_gnl(buffer, '\n') && last_line_boole)
	{
		last_line_boole = read(fd, str, BUFFER_SIZE);
		if (last_line_boole == -1)
		{
			if (buffer)
				free(buffer);
			return (free(str), NULL);
		}
		str[last_line_boole] = 0;
		buffer = ft_strjoin_gnl(buffer, str);
	}
	free(str);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer[256];
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer[fd] = ft_read_gnl(buffer[fd], fd);
	if (!buffer[fd])
		return (0);
	next_line = ft_next_line_gnl(buffer[fd]);
	buffer[fd] = ft_nlsplit_gnl(buffer[fd]);
	return (next_line);
}
