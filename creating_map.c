/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 08:54:50 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/08 16:27:10 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char	**map(char **argv)
{
	int		rows_in_map;
	int		fd;
	char	**map;
	int		i;

	fd = open(argv[1], O_RDONLY);
	rows_in_map = count_rows(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	map = (char **)malloc((rows_in_map) * sizeof(char));
	if (map == NULL)
		return (0);
	i = 0;
	while (rows_in_map >= i)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close (fd);
	return (map);
}

int	count_rows(int fd)
{
	int		number_rows;
	char	*part_buffer;
	int		read_buffer;
	int		i;

	number_rows = 0;
	read_buffer = 1;
	part_buffer = (char *)malloc((10 + 1) * sizeof(char));
	if (part_buffer == NULL)
		return (0);
	while (read_buffer != 0)
	{
		read_buffer = read(fd, part_buffer, 10);
		if (read_buffer == -1)
		{
			free(part_buffer);
			return (0);
		}
		part_buffer[read_buffer] = '\0';
		i = 0;
		number_rows = count_rows2(part_buffer, number_rows, i);
	}
	free(part_buffer);
	return (number_rows + 1);
}

int	count_rows2(char *part_buffer, int counter, int i)
{
	while (part_buffer[i] != '\0')
	{
		if (part_buffer[i] == '\n')
			counter++;
		i++;
	}
	return (counter);
}
