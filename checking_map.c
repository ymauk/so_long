/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:43:29 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/08 14:52:37 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void	checking_map(char **map)
{
	checking_contain(map);
	checking_rectangle(map);
	checking_walls(map);
	checking_valid_characters(map);
	checking_accessibility(map);
}

void	checking_contain(char **map)
{
	char	ecp;
	int		counter;

	ecp = 'E';
	counter = checking_contain2(map, ecp);
	if (counter != 1)
		error_handling(1, map);
	ecp = 'C';
	counter = checking_contain2(map, ecp);
	if (counter < 1)
		error_handling(1, map);
	ecp = 'P';
	counter = checking_contain2(map, ecp);
	if (counter != 1)
		error_handling(1, map);
}

int	checking_contain2(char **map, char ecp)
{
	int	counter;
	int	i;
	int	j;

	counter = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == ecp)
				counter += 1;
			j++;
		}
		i++;
	}
	return (counter);
}

void	checking_rectangle(char **map)
{
	int	i;
	int	number_first_column;
	int	number_rest_column;

	i = 1;
	number_first_column = counting_columns2(map, 0);
	while (map[i] != NULL)
	{
		number_rest_column = counting_columns2(map, i);
		if (number_first_column != number_rest_column)
			error_handling(2, map);
		i++;
	}
}

void	checking_walls(char **map)
{
	int	j;
	int	i;
	int	rows;
	int	columns;

	i = 0;
	rows = counting_rows(map);
	columns = counting_columns(map);
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0' && map[i][j] != '\n')
		{
			if (map[0][j] != '1' || map[rows - 1][j] != '1' ||
				map[i][0] != '1' || map[i][columns - 1] != '1')
				error_handling(3, map);
			j++;
		}
		i++;
	}
}
