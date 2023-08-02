/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:28:24 by sgluck            #+#    #+#             */
/*   Updated: 2023/08/02 07:17:41 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../gnl/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

typedef struct s_map
{
	char	*map;
	int		x;
	int		y;
}	t_map;

typedef struct s_img_types {
	void	*player;
	void	*collectible;
	void	*exit;
	void	*wall;
	void	*floor;
}	t_img_types;

typedef struct s_player {
	int	x_pos;
	int	y_pos;
	int	moves;
}	t_player;

typedef struct s_collectibles {
	int	total;
	int	got;
}	t_collectibles;

typedef struct s_game
{
	t_collectibles	col;
	t_img_types		images;
	t_map			*map;
	t_player		player;
	void			*mlx;
	void			*mlx_win;
	char			*filename;
	int				exit_open;
}	t_game;

void	init_game(t_game *game);
void	init_error(t_map *map, char *string);
void	add_line_error(char *line, char *newline, t_map *map);
void	win_game(t_game *game);
void	set_value(t_map *map, char value, int x, int y);
void	check_input(int argc, char **argv);
void	set_player_start_position(t_game *game);
void	set_collectible_count(t_game *game);
void	map_to_window(t_game *game);
void	set_image_values(void *mlx, t_img_types *images);
void	check_images(t_game *game);
void	setup_image(t_game *game, int x, int y);
void	game_exit_success(t_game *game);
void	game_exit_failure(t_game *game, char *message);
void	free_map(t_map *map);
void	open_exit(t_game *game);
char	get_value(t_map *map, int x, int y);
int		print_map(t_map *map);
int		validate_borders(t_map *map);
int		validate_contents(t_map *map);
int		validate_map(t_game *game);
int		set_map(t_game *game, int fd);
int		get_char_count(char *string, char character);
int		check_all_reachable(t_game *game);
int	place_images(t_game *game, t_map *map);
int		place_images_loop(t_game *game);
int		hook_actions(int keycode, t_game *game);
int		close_window(t_game *game);
int		expose_window(t_game *game);
int		game_exit(t_game *game);
int		destroy_images(t_game *game);

#endif
