/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handling_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:49:04 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/19 10:05:31 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	keyhook_b(mlx_key_data_t keydata, void *param)
{
	t_vars	*data;

	data = param;
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_up_b(data);
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_down_b(data);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_left_b(data);
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_right_b(data);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
}

void	move_up_b(t_vars *data)
{
	if (data->p_y > 0 && data->map[(data->p_y / 32) - 1][data->p_x / 32] != '1')
	{
		data->image[P]->instances->y -= 32;
		data->p_x = data->image[P]->instances->x;
		data->p_y = data->image[P]->instances->y;
		data->counter++;
		collectable_exit_enemy_b(data, data->p_x / 32, data->p_y / 32);
		ft_printf("Steps made: %d\n", data->counter);
	}
}

void	move_down_b(t_vars *data)
{
	if (data->map[(data->p_y / 32) + 1][data->p_x / 32] != '1')
	{
		data->image[P]->instances->y += 32;
		data->p_x = data->image[P]->instances->x;
		data->p_y = data->image[P]->instances->y;
		data->counter++;
		collectable_exit_enemy_b(data, data->p_x / 32, data->p_y / 32);
		ft_printf("Steps made: %d\n", data->counter);
	}
}

void	move_left_b(t_vars *data)
{
	if (data->map[data->p_y / 32][(data->p_x / 32) - 1] != '1')
	{
		data->image[P]->instances->x -= 32;
		data->p_x = data->image[P]->instances->x;
		data->p_y = data->image[P]->instances->y;
		data->counter++;
		collectable_exit_enemy_b(data, data->p_x / 32, data->p_y / 32);
		ft_printf("Steps made: %d\n", data->counter);
	}
}

void	move_right_b(t_vars *data)
{
	if (data->map[data->p_y / 32][(data->p_x / 32) + 1] != '1')
	{
		data->image[P]->instances->x += 32;
		data->p_x = data->image[P]->instances->x;
		data->p_y = data->image[P]->instances->y;
		data->counter++;
		collectable_exit_enemy_b(data, data->p_x / 32, data->p_y / 32);
		ft_printf("Steps made: %d\n", data->counter);
	}
}
