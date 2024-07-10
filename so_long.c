/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:13:55 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/09 17:09:40 by ymauk            ###   ########.fr       */
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
	int			pd;
	char		**created_map;

	pd = argc;
	created_map = map(argv);
	checking_map(created_map);
	window_size(created_map, &size_w);
	data.mlx = mlx_init(size_w.x * 32, size_w.y * 32, "so_long", true);
	handling_images(&data, created_map, &size_w);
	mlx_loop(data.mlx);
	return (0);
}
#start funktion bauen in der argv == 2 gemacht wird sowie auf die map endung .ber geschaut wird
sowie wie das erstellen der map gemacht wird