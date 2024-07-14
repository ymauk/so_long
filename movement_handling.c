/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:49:04 by ymauk             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/07/12 16:30:35 by ymauk            ###   ########.fr       */
=======
/*   Updated: 2024/07/14 17:17:31 by ymauk            ###   ########.fr       */
>>>>>>> 14Juli 17:34 Aktuellster Stand
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_vars	*data;

	data = param;
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_up(data);
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_down(data);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_left(data);
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_right(data);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
<<<<<<< HEAD
=======
	{
		mlx_delete_image(data->mlx, data->img);
		free_map(data);
>>>>>>> 14Juli 17:34 Aktuellster Stand
		mlx_close_window(data->mlx);
}

void	move_up(t_vars *data)
{
	int	x;
	int	y;

	x = data->p_x / 32;
	y = data->p_y / 32;
	if (y > 0 && data->map[y - 1][x] != '1')
	{
		data->player_img->instances[0].y -= 32;
		data->p_x = data->player_img->instances[0].x;
		data->p_y = data->player_img->instances[0].y;
		data->counter++;
		collectable_exit(data, x, y - 1);
		ft_printf("Steps made: %d\n", data->counter);
	}
}

void	move_down(t_vars *data)
{
	int	x;
	int	y;

	x = data->p_x / 32;
	y = data->p_y / 32;
	if (data->map[y + 1][x] != '1')
	{
		data->player_img->instances[0].y += 32;
		data->p_x = data->player_img->instances[0].x;
		data->p_y = data->player_img->instances[0].y;
		data->counter++;
		collectable_exit(data, x, y + 1);
		ft_printf("Steps made: %d\n", data->counter);
	}
}

void	move_left(t_vars *data)
{
	int	x;
	int	y;

	x = data->p_x / 32;
	y = data->p_y / 32;
	if (data->map[y][x - 1] != '1')
	{
		data->player_img->instances[0].x -= 32;
		data->p_x = data->player_img->instances[0].x;
		data->p_y = data->player_img->instances[0].y;
		data->counter++;
		collectable_exit(data, x - 1, y);
		ft_printf("Steps made: %d\n", data->counter);
	}
}

void	move_right(t_vars *data)
{
	int	x;
	int	y;

	x = data->p_x / 32;
	y = data->p_y / 32;
	if (data->map[y][x + 1] != '1')
	{
		data->player_img->instances[0].x += 32;
		data->p_x = data->player_img->instances[0].x;
		data->p_y = data->player_img->instances[0].y;
		data->counter++;
		collectable_exit(data, x + 1, y);
		ft_printf("Steps made: %d\n", data->counter);
	}
}
