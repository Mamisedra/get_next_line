/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:31:19 by mranaivo          #+#    #+#             */
/*   Updated: 2024/04/11 13:43:11 by mranaivo         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extractline(char *store)
{
	int		i;
	char	*reste;

	if (!store)
		return (NULL);
	i = 0;
	while (store[i] && store[i] != '\n')
		i++;
	if (store[i] == '\n')
		i++;
	reste = malloc(sizeof(char) * ((i + 1)));
	if (!reste)
		return (NULL);
	ft_strcpy(store, reste);
	return (reste);
}

char	*ft_getreste(char *store)
{
	int		i;
	int		j;
	char	*reste;

	i = 0;
	while (store[i] != '\n' && store[i])
		i++;
	if (store[i] == '\0')
		return (free(store), NULL);
	else
		i++;
	j = 0;
	while (store[i + j] != '\0')
		j++;
	reste = malloc((j + 1) * sizeof(char));
	if (!reste)
		return (NULL);
	j = 0;
	while (store[i] != '\0')
		reste[j++] = store[i++];
	reste[j] = '\0';
	free(store);
	return (reste);
}

char	*ft_read(char *reste, int fd)
{
	char	*buffer;
	int		read_line;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (ft_strchr(reste, '\n') < 0)
	{
		read_line = read(fd, buffer, BUFFER_SIZE);
		if (read_line < 0)
			return (free(buffer), NULL);
		if (read_line == 0)
			break ;
		buffer[read_line] = '\0';
		reste = ft_strjoin(reste, buffer);
	}
	free(buffer);
	return (reste);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*reste = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reste = ft_read(reste, fd);
	if (!reste || reste[0] == '\0')
	{
		free(reste);
		return (NULL);
	}
	line = ft_extractline(reste);
	reste = ft_getreste(reste);
	return (line);
}
