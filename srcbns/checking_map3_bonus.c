/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:02:00 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/17 13:44:13 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	checking_valid_characters(t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0' && data->map[i][j] != '\n')
		{
			if (data->map[i][j] != '0' && data->map[i][j] != '1'
			&& data->map[i][j] != 'C' && data->map[i][j] != 'P'
			&& data->map[i][j] != 'E' && data->map[i][j] != 'X')
				error_handling(4, data);
			j++;
		}
		i++;
	}
}

void	place_x(t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0' && data->map[i][j] != '\n')
		{
			if (data->map[i][j] == 'X')
			{
				mlx_image_to_window(data->mlx, data->image[X], j * 32, i * 32);
				data->x_x = j * 32;
				data->x_y = i * 32;
			}
			j++;
		}
		i++;
	}
}

void	window_size(t_vars *data, t_window *size_w)
{
	size_w->x = counting_columns(data);
	size_w->y = counting_rows(data);
}

void	display_text_lose(t_vars *data)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = ((counting_columns(data) * 32) - (30 * 8)) / 2;
	y1 = counting_rows(data) / 2 - 15;
	x2 = ((counting_columns(data) * 32) - (27 * 8)) / 2;
	y2 = y1 + 30;
	place_g_w(data);
	mlx_put_string(data->mlx, "Sorry, you lost this time   :(", x1, y2);
	mlx_put_string(data->mlx, "Press exit to leave!", x2, y2 + 60);
}
