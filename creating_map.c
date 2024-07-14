/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannismauk <yannismauk@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 08:54:50 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/14 12:59:09 by yannismauk       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void	map(char **argv, t_vars *data)
{
	int		rows_in_map;
	int		fd;
	int		i;

	fd = open(argv[1], O_RDONLY);
	rows_in_map = count_rows(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	data->map = (char **)malloc((rows_in_map) * sizeof(char));
	if (data->map == NULL)
		error_handling(6, data);
	i = 0;
	while (rows_in_map >= i)
	{
		data->map[i] = get_next_line(fd);
		i++;
	}
	data->map[i] = NULL;
	close (fd);
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
