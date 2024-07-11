/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:13:55 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/11 16:20:11 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_window	size_w;
	t_vars		data;

	data.map = start(argc, argv);
	window_size(data.map, &size_w);
	data.mlx = mlx_init(size_w.x * 32, size_w.y * 32, "so_long", true);
	handling_images(&data);
	data.player_img = data.image[P];
	data.counter = 0;
	// display_counter(&data);
	mlx_key_hook(data.mlx, keyhook, &data);
	mlx_loop(data.mlx);
	return (0);
}
