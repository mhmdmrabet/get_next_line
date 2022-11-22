/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:19:35 by mmrabet           #+#    #+#             */
/*   Updated: 2022/11/19 09:19:35 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

size_t	ft_strlen(const char *s);
void	ft_get_stash_from_read(int fd, char *stash);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_clean_stash(char *stash);
char	*ft_join_and_free_tmp(char *buffer, char *buffer_from_read);
char	*ft_extract_line_from_stash(char *stash);
char	*ft_strjoin(char const *buffer, char const *buffer_from_read);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);

#endif
