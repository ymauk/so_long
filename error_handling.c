/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:03:08 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/05 11:42:16 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void	error_handling(int number_error)
{
	if (number_error == 1)
		ft_printf("Your map is not correctly filled with C.E.Ps!\n");
	if (number_error == 2)
		ft_printf("Your map is not rectangular!\n");
	if (number_error == 3)
		ft_printf("Your map is not surrounded by walls!\n");
	if (number_error == 4)
		ft_printf("Your map as invalid characters!\n");
	exit(1);
}
