/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:03:08 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/17 13:55:05 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_handling(int number_error, t_vars *data)
{
	if (number_error == 0)
		ft_printf("Error\nYour arguments are not valid!\n");
	if (number_error == 1)
		ft_printf("Error\nYour map is not correctly filled with C.E.Ps!\n");
	else if (number_error == 2)
		ft_printf("Error\nYour map is not rectangular!\n");
	else if (number_error == 3)
		ft_printf("Error\nYour map is not surrounded by walls!\n");
	else if (number_error == 4)
		ft_printf("Error\nYour map has invalid characters!\n");
	else if (number_error == 5)
		ft_printf("Error\nYour map has no valid path!\n");
	else if (number_error == 6)
		ft_printf("Error\nAllocation failed!\n");
	else if (number_error == 7)
		ft_printf("Error\nloadimg png has failed!\n");
	else if (number_error == 8)
		ft_printf("Error\ntexture to image has failed!\n");
	else if (number_error == 9)
		ft_printf("Error\nimage to window has failed!\n");
	else if (number_error == 10)
		ft_printf("Error\nYour map is not valid!\n");
	free_all(data);
	exit(1);
}
