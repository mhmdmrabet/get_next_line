/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:40:24 by mmrabet           #+#    #+#             */
/*   Updated: 2022/11/19 09:40:24 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *stash, char const *b)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(b) + 1));
	if (!str)
		return (NULL);
	while (stash[i])
	{
		str[j] = stash[i];
		i++;
		j++;
	}
	i = 0;
	while (b[i])
	{
		str[j] = b[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	result;
	size_t	i;
	char	*str;
	void	*ptr;

	i = 0;
	if (nmemb && size && (nmemb * size / size != nmemb))
		return (NULL);
	result = (nmemb * size);
	ptr = (void *)malloc(result);
	if (!ptr)
		return (NULL);
	str = (char *) ptr;
	while (i < result)
	{
		*str = '\0';
		str++;
		i++;
	}
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	if (c == 0)
		return (ft_strlen(s) + (char *)s);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(&s[i]));
		i++;
	}
	return (NULL);
}

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
