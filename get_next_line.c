/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:17:01 by mmrabet           #+#    #+#             */
/*   Updated: 2022/11/19 09:17:01 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stash = ft_get_stash_from_read(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_store_line(stash);
	stash = ft_move_to_next_line(stash);
	return (line);
}

char	*ft_get_stash_from_read(int fd, char *stash)
{
	char	*buffer;
	int		result;

	if (!stash)
		stash = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	result = 1;
	while (result > 0)
	{
		result = read(fd, buffer, BUFFER_SIZE);
		if (result == -1)
		{
			free(buffer);
			return (NULL);
		}	
		buffer[result] = '\0';
		stash = ft_join_and_free_buff(stash, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (stash);
}

char	*ft_store_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] && stash[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_move_to_next_line(char *stash)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(stash) - i + 1), sizeof(char));
	i++;
	while (stash[i])
		line[j++] = stash[i++];
	free(stash);
	return (line);
}

char	*ft_join_and_free_buff(char *buffer, char *buffer_from_read)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, buffer_from_read);
	free(buffer);
	return (tmp);
}
