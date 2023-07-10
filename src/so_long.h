#ifndef SO_LONG_H
#define SO_LONG_H

#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include "../gnl/get_next_line.h"
#include "../mlx_linux/mlx.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_map
{
    char *map;
    int x;
    int y;
} t_map;

typedef struct s_img_types {
    void *player;
    void *collectible;
    void *exit;
    void *wall;
    void *floor;
} t_img_types;

typedef struct s_player {
    int x_pos;
    int y_pos;
    int moves;
} t_player;

typedef struct s_game
{
    void *mlx;
    void *mlx_win;
    t_map   *map;
    t_img_types images;
    t_player player;
    
} t_game;

void    init_map(t_game *game);
char get_value(t_map *map, int x, int y);
int print_map(t_map *map);
int validate_borders(t_map *map);
int validate_contents(t_map *map);
int validate_map(t_map *map);
void check_input(int argc, char **argv);
void set_player_start_position(t_game *game);

void map_to_window(t_game *game);
int hook_actions(int keycode, t_game *game);

#endif