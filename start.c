/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:10:36 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/10 09:31:28 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char	**start(int argc, char **argv)
{
	char	**created_map;

	created_map = NULL;
	if (argc == 2)
	{
		if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
			error_handling('0', created_map);
		created_map = map(argv);
		checking_map(created_map);
	}
	else
		error_handling('0', created_map);
	return (created_map);
}
