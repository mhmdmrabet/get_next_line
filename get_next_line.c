/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:51:29 by mmrabet           #+#    #+#             */
/*   Updated: 2022/11/20 10:51:29 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char			*str;
	unsigned int	s_len;
	unsigned int	i;

	i = 0;
	s_len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!str)
		return (NULL);
	while (i < s_len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_dup_and_free_buff(char *stash, char *str)
{
	char	*tmp;

	tmp = ft_strdup(stash);
	free(str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*tmp;
	int			result;
	int			i;
	int			j;

	j = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	i = 0;
	tmp = ft_calloc(1, 1);
	if (!tmp)
		return (NULL);
	result = 1;
	while (result > 0)
	{
		result = read(fd, buffer, BUFFER_SIZE);
		if (result == -1)
			return (NULL);
		buffer[result] = '\0';
		if (stash[0])
		{
			tmp = ft_dup_and_free_buff(stash, tmp);
		}
		tmp = ft_join_and_free_buff(tmp, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (!tmp[0])
		return (free(tmp), NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
			i++;
		stash[j] = tmp[i];
		j++;
		i++;
	}
	stash[j] = '\0';
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (free(tmp), NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		line[i] = tmp[i];
		i++;
	}
	if (tmp[i] && tmp[i] == '\n')
		line[i] = '\n';
	free(tmp);
	return (line);
}


// int	main(void)
// {
// 	char	*line;
// 	const int	fd = open("gnlTester/files/empty", O_RDONLY);
// 	int			i;

// 	i = 0;
// 	while (i < 1)
// 	{
// 		line = get_next_line(fd);
// 		printf("LINE : %s\n", line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }
