/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:05:20 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/08 15:13:45 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/Libft/libft.h"
# include "lib/printf/ft_printf.h"
# include "lib/get_next_line/get_next_line.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

char		**map(char **argv);
int			count_rows(int fd);
int			count_rows2(char *part_buffer, int counter, int i);

void		checking_map(char **map);
void		checking_contain(char **map);
int			checking_contain2(char **map, char ecp);
void		checking_rectangle(char **map);
void		checking_walls(char **map);

void		checking_accessibility(char **map);
t_point		find_p_position(char **map);
void		flood_fill(char **tab, t_point size, t_point begin);
void		fill(char **tab, t_point size, t_point cur, char to_fill);
void		check_flood_fill(char **map_dup, char **map);

void		checking_valid_characters(char **map);

int			counting_rows(char **map);
int			counting_columns(char **map);
int			counting_columns2(char **map, int which_row);
char		**duplicate_map(char **map, char **map_dup);

void		error_handling(int number_error, char **map);

void		free_map(char **map);

#endif