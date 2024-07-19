/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:05:20 by ymauk             #+#    #+#             */
/*   Updated: 2024/07/19 09:59:03 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../lib/Libft/libft.h"
# include "../lib/printf/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libmlx/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <fcntl.h>

# define TEXTURES			6
# define G					0
# define P					1
# define W					2
# define C					3
# define E					4
# define X					5

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_window
{
	int	x;
	int	y;
}	t_window;

typedef struct s_vars
{
	mlx_texture_t	*textures[TEXTURES];

	mlx_image_t		*image[TEXTURES];
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t		*img;
	mlx_key_data_t	keydata;
	mlx_image_t		*player_img;

	char			**map;
	int				counter;
	int				p_x;
	int				p_y;
	int				x_x;
	int				x_y;
	int				amount_c;
	int				c_counter;

}	t_vars;

void		map_b(char **argv, t_vars *data);
int			count_rows_b(int fd);
int			count_rows2_b(char *part_buffer, int counter, int i);

void		checking_map_b(t_vars *data);
void		checking_contain_b(t_vars *data);
int			checking_contain2_b(t_vars *data, char ecp);
void		checking_rectangle_b(t_vars *data);
void		checking_walls_b(t_vars *data);

void		checking_accessibility_b(t_vars *data);
t_point		find_p_position_b(t_vars *data);
void		flood_fill_b(char **tab, t_point size, t_point begin);
void		fill_b(char **tab, t_point size, t_point cur, char to_fill);
void		check_flood_fill_b(char **map_dup, t_vars *data);

void		checking_valid_characters_b(t_vars *data);
void		place_x_b(t_vars *data);
void		display_text_lose_b(t_vars *data);
void		window_size_b(t_vars *data, t_window *size_w);

int			counting_rows_b(t_vars *data);
int			counting_columns_b(t_vars *data);
int			counting_columns2_b(t_vars *data, int which_row);
char		**duplicate_map_b(t_vars *data, char **map_dup);
void		find_player_b(t_vars *data);

void		error_handling_b(int number_error, t_vars *data);

void		free_all_b(t_vars *data);
void		free_map_dup_b(char **map_dup);

void		collectable_exit_enemy_b(t_vars *data, int x, int y);
void		check_z_instances_b(t_vars *data);
void		display_text_b(t_vars *data);
void		null_everything_b(t_vars *data);

void		handling_images_b(t_vars *data);
void		place_c_e_b(t_vars *data);
void		place_g_w_b(t_vars *data);
void		place_p_b(t_vars *data);

void		start_b(int argc, char **argv, t_vars *data);

void		keyhook_b(mlx_key_data_t keydata, void *param);
void		move_up_b(t_vars *data);
void		move_down_b(t_vars *data);
void		move_left_b(t_vars *data);
void		move_right_b(t_vars *data);

#endif