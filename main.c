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

int	main(void)
{
	const int	fd = open("explication.txt", O_RDONLY);
	char		*line;
	int			i;

	i = 0;
	while (i < 4)
	{
		line = get_next_line(fd);
		printf("LINE %d : %s\n", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
