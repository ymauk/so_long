/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannismauk <yannismauk@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:13:55 by ymauk             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/07/14 12:53:17 by yannismauk       ###   ########.fr       */
=======
/*   Updated: 2024/07/14 17:15:52 by ymauk            ###   ########.fr       */
>>>>>>> 14Juli 17:34 Aktuellster Stand
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

	start(argc, argv, &data);
	window_size(&data, &size_w);
	data.mlx = mlx_init(size_w.x * 32, size_w.y * 32, "so_long", true);
	mlx_set_window_limit(data.mlx, size_w.x * 32,
		size_w.y * 32, size_w.x * 32, size_w.y * 32);
	data.c_counter = 0;
	data.amount_c = 0;
	handling_images(&data);
	data.player_img = data.image[P];
	// display_counter(&data);
	mlx_key_hook(data.mlx, keyhook, &data);
	mlx_loop(data.mlx);
	free_all(&data);
	mlx_terminate(data.mlx);
	return (0);
}
