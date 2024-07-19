/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:13:55 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/19 12:20:39 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_window	size_w;
	t_vars		data;

	null_everything(&data);
	start(argc, argv, &data);
	window_size(&data, &size_w);
	data.mlx = mlx_init(size_w.x * 32, size_w.y * 32, "so_long", true);
	mlx_set_window_limit(data.mlx, size_w.x * 32,
		size_w.y * 32, size_w.x * 32, size_w.y * 32);
	data.c_counter = 0;
	data.amount_c = 0;
	handling_images(&data);
	mlx_key_hook(data.mlx, keyhook, &data);
	mlx_loop(data.mlx);
	free_all(&data);
	mlx_terminate(data.mlx);
	return (0);
}
