#include "so_long.h"
typedef struct s_img_types {
    void *player;
    void *collectible;
    void *exit;
    void *wall;
    void *floor;
} t_img_types;

static void set_image_values(void *mlx, t_img_types *images)
{
    int width;
    int height;

    images->player = mlx_xpm_file_to_image(mlx, "assets/sprites/player/front.xpm", &width, &height);
    images->collectible = mlx_xpm_file_to_image(mlx, "assets/sprites/coin-bag.xpm", &width, &height);
    images->exit = mlx_xpm_file_to_image(mlx, "assets/sprites/exit-closed.xpm", &width, &height);
    images->floor = mlx_xpm_file_to_image(mlx, "assets/sprites/floor.xpm", &width, &height);
    images->wall = mlx_xpm_file_to_image(mlx, "assets/sprites/wall.xpm", &width, &height);

}

static void setup_image(void *mlx, void *mlx_win, t_img_types images, t_map *map, int x, int y)
{
    if (get_value(map, x + 1, y + 1) == '1')
        mlx_put_image_to_window(mlx, mlx_win, images.wall, x * 32, y * 32);
    else if (get_value(map, x + 1, y + 1) == '0')
        mlx_put_image_to_window(mlx, mlx_win, images.floor, x * 32, y * 32);
    else if (get_value(map, x + 1, y + 1) == 'C')
        mlx_put_image_to_window(mlx, mlx_win, images.collectible, x * 32, y * 32);
    else if (get_value(map, x + 1, y + 1) == 'P')
        mlx_put_image_to_window(mlx, mlx_win, images.player, x * 32, y * 32);
    else if (get_value(map, x + 1, y + 1) == 'E')
        mlx_put_image_to_window(mlx, mlx_win, images.exit, x * 32, y * 32);
    else
        printf("error setup image %c\n", get_value(map, x, y));
}

static int place_images(void *mlx, void *mlx_win, t_map *map, t_img_types images)
{
    int y;
    int x;

    y = 0;
    while(y < map->y)
    {
        x = 0;
        while(x < map->x)
        {
            setup_image(mlx, mlx_win, images, map, x, y);
            x++;
        }
        y++;
    }
    return (1);
}


void map_to_window(t_game *game)
{
   
    t_img_types images;

    game->mlx = mlx_init();
    game->mlx_win = mlx_new_window(game->mlx, game->map->x * 32, game->map->y * 32, "so_long");
    set_image_values(game->mlx, &images);
    place_images(game->mlx, game->mlx_win, game->map, images);
    //hook
    mlx_loop(game->mlx);
}