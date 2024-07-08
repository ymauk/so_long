/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:13:55 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/08 15:08:50 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	**created_map;
	int		i;

	i = 0;
	if (argc == 2)
	{
		created_map = map(argv);
		checking_map(created_map);
	}
	return (0);
}
