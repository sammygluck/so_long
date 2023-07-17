#include "so_long.h"

void map_to_window(t_game *game)
{
    game->mlx = mlx_init();
    game->mlx_win = mlx_new_window(game->mlx, game->map->x * 32, game->map->y * 32, "so_long");
    set_image_values(game->mlx, &(game->images));
    //if (!set_image.....)
        //exit_free
    place_images(game->mlx, game->mlx_win, game->map, game->images);
    //hook
    mlx_key_hook(game->mlx_win, hook_actions, game);
    mlx_hook(game->mlx_win, 17, 0, close_window, game);
    mlx_loop_hook(game->mlx, place_images_loop, game);
    mlx_loop(game->mlx);
}