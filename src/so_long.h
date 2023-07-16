#ifndef SO_LONG_H
#define SO_LONG_H

#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include "../gnl/get_next_line.h"
#include "../mlx_linux/mlx.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

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

typedef struct s_collectibles {
    int collectible_count;
    int found_collectibles;
} t_collectibles;

typedef struct s_game
{
    void *mlx;
    void *mlx_win;
    t_map   *map;
    t_img_types images;
    t_player player;
    t_collectibles collectibles; 
    char *filename;
} t_game;

void    init_map(t_game *game);
char get_value(t_map *map, int x, int y);
void set_value(t_map *map, char value, int x, int y);
int print_map(t_map *map);
int validate_borders(t_map *map);
int validate_contents(t_map *map);
int validate_map(t_game *game);
void check_input(int argc, char **argv);
void set_player_start_position(t_game *game);
void set_collectible_count(t_game *game);
int get_char_count(char *string, char character);
int check_all_reachable(t_game *game);

void map_to_window(t_game *game);
int place_images(void *mlx, void *mlx_win, t_map *map, t_img_types images);
int hook_actions(int keycode, t_game *game);
int close_window(t_game *game);
int expose_window(t_game *game);
int game_exit(t_game *game);
void free_map(t_map *map);
void init_error(t_map *map, char *string);

#endif