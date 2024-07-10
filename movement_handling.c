/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:49:04 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/10 11:14:21 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_vars	*data;

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
}

void	move_up(t_vars *data)
{
	data->img->instances[0].y += 32;
}

void	move_down(t_vars *data)
{
	data->img->instances[0].y -= 32;
}

void	move_left(t_vars *data)
{
	data->img->instances[0].x -= 32;
}

void	move_right(t_vars *data)
{
	data->img->instances[0].x += 32;
}
