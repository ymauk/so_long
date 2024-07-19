/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:49:28 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/17 17:03:42 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	collectable_exit_enemy(t_vars *data, int x, int y)
{
	if (data->map[y][x] == 'X')
	{
		display_text_lose(data);
	}
	if (data->map[y][x] == 'C')
	{
		data->map[y][x] = '0';
		data->amount_c--;
		mlx_image_to_window(data->mlx, data->image[G], x * 32, y * 32);
		check_z_instances(data);
	}
	if (data->map[y][x] == 'E' && data->amount_c == 0)
	{
		display_text(data);
	}
}

void	check_z_instances(t_vars *data)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (data->image[G]->instances[i].z < data->image[P]->instances[0].z)
		i++;
	z = data->image[G]->instances[i].z + 1;
	data->image[P]->instances[0].z = z;
}

void	display_text(t_vars *data)
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
	mlx_put_string(data->mlx, "Congratulations, you won :)", x1, y2);
	mlx_put_string(data->mlx, "Press exit to leave!", x2, y2 + 60);
}

void	null_everything(t_vars *data)
{
	int	i;

	i = 0;
	data->map = NULL;
	while (i < TEXTURES)
	{
		data->textures[i] = NULL;
		i++;
	}
}
