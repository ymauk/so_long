/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannismauk <yannismauk@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:03:08 by ymauk             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/07/14 13:00:37 by yannismauk       ###   ########.fr       */
=======
/*   Updated: 2024/07/14 17:01:42 by ymauk            ###   ########.fr       */
>>>>>>> 14Juli 17:34 Aktuellster Stand
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void	error_handling(int number_error, t_vars *data)
{
	if (number_error == 0)
		ft_printf("Your arguments are not valid!\n");
	if (number_error == 1)
		ft_printf("Your map is not correctly filled with C.E.Ps!\n");
	else if (number_error == 2)
		ft_printf("Your map is not rectangular!\n");
	else if (number_error == 3)
		ft_printf("Your map is not surrounded by walls!\n");
	else if (number_error == 4)
		ft_printf("Your map has invalid characters!\n");
	else if (number_error == 5)
		ft_printf("Your map has no valid path!\n");
	else if (number_error == 6)
		ft_printf("Allocation failed!\n");
	else if (number_error == 7)
		ft_printf("loadimg png has failed!\n");
	else if (number_error == 8)
		ft_printf("texture to image has failed!\n");
	else if (number_error == 9)
		ft_printf("image to window has failed!\n");
<<<<<<< HEAD
	free_all(data);
=======
	free_map(data);
>>>>>>> 14Juli 17:34 Aktuellster Stand
	exit(1);
}
