/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:43:29 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/19 10:02:02 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	checking_map_b(t_vars *data)
{
	checking_contain_b(data);
	checking_rectangle_b(data);
	checking_walls_b(data);
	checking_valid_characters_b(data);
	checking_accessibility_b(data);
}

void	checking_contain_b(t_vars *data)
{
	char	ecpx;
	int		counter;

	ecpx = 'E';
	counter = checking_contain2_b(data, ecpx);
	if (counter != 1)
		error_handling_b(1, data);
	ecpx = 'C';
	counter = checking_contain2_b(data, ecpx);
	if (counter < 1)
		error_handling_b(1, data);
	ecpx = 'P';
	counter = checking_contain2_b(data, ecpx);
	if (counter != 1)
		error_handling_b(1, data);
	ecpx = 'X';
	counter = checking_contain2_b(data, ecpx);
	if (counter != 1)
		error_handling_b(1, data);
}

int	checking_contain2_b(t_vars *data, char ecp)
{
	int	counter;
	int	i;
	int	j;

	counter = 0;
	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0' && data->map[i][j] != '\n')
		{
			if (data->map[i][j] == ecp)
				counter += 1;
			j++;
		}
		i++;
	}
	return (counter);
}

void	checking_rectangle_b(t_vars *data)
{
	int	i;
	int	number_first_column;
	int	number_rest_column;

	i = 1;
	number_first_column = counting_columns2_b(data, 0);
	while (data->map[i] != NULL)
	{
		number_rest_column = counting_columns2_b(data, i);
		if (number_first_column != number_rest_column)
			error_handling_b(2, data);
		i++;
	}
}

void	checking_walls_b(t_vars *data)
{
	int	j;
	int	i;
	int	rows;
	int	columns;

	i = 0;
	rows = counting_rows_b(data);
	columns = counting_columns_b(data);
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0' && data->map[i][j] != '\n')
		{
			if (data->map[0][j] != '1' || data->map[rows - 1][j] != '1' ||
				data->map[i][0] != '1' || data->map[i][columns - 1] != '1')
				error_handling_b(3, data);
			j++;
		}
		i++;
	}
}
