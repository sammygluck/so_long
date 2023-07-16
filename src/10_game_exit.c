#include "so_long.h"

//basic for testing
int close_window(t_game *game)
{
    game_exit(game);
    return (0);
}

static int destroy_images(t_game *game)
{
    
    if (game->images.collectible)
        mlx_destroy_image(game->mlx, game->images.collectible);
    if (game->images.exit)
        mlx_destroy_image(game->mlx, game->images.exit);
    if (game->images.floor)
        mlx_destroy_image(game->mlx, game->images.floor);
    if (game->images.player)
        mlx_destroy_image(game->mlx, game->images.player);
    if (game->images.wall)
        mlx_destroy_image(game->mlx, game->images.wall);
    return (0);
}

void free_map(t_map *map)
{
    if (map->map)
        free(map->map);
    if (map)
        free(map);
}

//exiting game
int game_exit(t_game *game)
{
    //1. Destroy mlx_imgs
    destroy_images(game);
    //2. Destroy mlx_win
    if (game->mlx_win)
        mlx_destroy_window(game->mlx, game->mlx_win);
    //3. Destroy mlx
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
    //4. free map
    if (game->map)
        free_map(game->map);
    exit(EXIT_SUCCESS);
    return (0); 
}