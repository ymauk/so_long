/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:05:20 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/05 11:38:39 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/Libft/libft.h"
# include "lib/printf/ft_printf.h"
# include "lib/get_next_line/get_next_line.h"

char	**map(char **argv);
int		count_rows(int fd);
int		count_rows2(char *part_buffer, int counter, int i);

void	checking_map(char **map);
void	checking_contain(char **map);
int		checking_contain2(char **map, char ecp);
void	checking_rectangle(char **map);
void	checking_walls(char **map);

void	checking_valid_characters(char **map);

int		counting_rows(char **map);
int		counting_columns(char **map);
int		counting_columns2(char **map, int which_row);

void	error_handling(int number_error);

#endif