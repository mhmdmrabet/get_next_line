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
	line = ft_extract_line_from_stash(stash);
	stash = ft_clean_stash(stash);
	return (line);
}

char	*ft_get_stash_from_read(int fd, char *stash)
{
	char	*buffer;
	int		result;

	if (!stash)
		stash = ft_calloc(1, 1);
	if (!stash)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	result = 1;
	while (result > 0 && (ft_strchr(buffer, '\n') == 0))
	{
		result = read(fd, buffer, BUFFER_SIZE);
		if (result == -1)
		{
			free(buffer);
			return (NULL);
		}	
		buffer[result] = '\0';
		stash = ft_join_and_free_buff(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*ft_extract_line_from_stash(char *stash)
{
	char	*line;
	int		len_line;
	int		i;

	i = 0;
	len_line = 0;
	if (!stash[i])
		return (NULL);
	while (stash[len_line] && stash[len_line] != '\n')
		len_line++;
	line = ft_calloc(len_line + 2, sizeof(char));
	if (!line)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] && stash[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_clean_stash(char *stash)
{
	char	*new_stash;
	int		stash_len;
	int		i;
	int		j;

	stash_len = ft_strlen(stash);
	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_calloc((stash_len - i + 1), sizeof(char));
	if (!new_stash)
		return (NULL);
	i++;
	while (stash[i])
		new_stash[j++] = stash[i++];
	free(stash);
	return (new_stash);
}
