/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:03:08 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/08 15:08:18 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void	error_handling(int number_error, char **map)
{
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
	free_map(map);
	exit(1);
}
