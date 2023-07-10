#include "so_long.h"


static void move_left(t_game *game)
{
    int x;
    int y;

    x = game->player.x_pos;
    y = game->player.y_pos;
    if (get_value(game->map, x - 1, y) == '1')
        return ;
    else if (get_value(game->map, x - 1, y) == 'C')
        game->collectibles.found_collectibles += 1;
    else if (get_value(game->map, x - 1, y) == 'E')
        if (game->collectibles.found_collectibles == game->collectibles.collectible_count)
            ft_printf("you won the game\n");
    set_value(game->map, '0', x, y);
    set_value(game->map, 'P', x - 1, y);
    place_images(game->mlx, game->mlx_win, game->map, game->images);

}

static void move_right(t_game *game)
{
    int x;
    int y;

    x = game->player.x_pos;
    y = game->player.y_pos;
    if (get_value(game->map, x + 1, y) == '1')
        return ;
    else if (get_value(game->map, x + 1, y) == 'C')
        game->collectibles.found_collectibles += 1;
    else if (get_value(game->map, x + 1, y) == 'E')
        if (game->collectibles.found_collectibles == game->collectibles.collectible_count)
            ft_printf("you won the game\n");
    set_value(game->map, '0', x, y);
    set_value(game->map, 'P', x + 1, y);
    place_images(game->mlx, game->mlx_win, game->map, game->images);
    
}

static void move_up(t_game *game)
{
    int x;
    int y;

    x = game->player.x_pos;
    y = game->player.y_pos;
    if (get_value(game->map, x, y - 1) == '1')
        return ;
    else if (get_value(game->map, x, y - 1) == 'C')
        game->collectibles.found_collectibles += 1;
    else if (get_value(game->map, x, y - 1) == 'E')
        if (game->collectibles.found_collectibles == game->collectibles.collectible_count)
            ft_printf("you won the game\n");
    set_value(game->map, '0', x, y);
    set_value(game->map, 'P', x, y - 1);
    place_images(game->mlx, game->mlx_win, game->map, game->images);
}

static void move_down(t_game *game)
{
    int x;
    int y;

    x = game->player.x_pos;
    y = game->player.y_pos;
    if (get_value(game->map, x, y + 1) == '1')
        return ;
    else if (get_value(game->map, x, y + 1) == 'C')
        game->collectibles.found_collectibles += 1;
    else if (get_value(game->map, x, y + 1) == 'E')
        if (game->collectibles.found_collectibles == game->collectibles.collectible_count)
            ft_printf("you won the game\n");
    set_value(game->map, '0', x, y);
    set_value(game->map, 'P', x, y + 1);
    place_images(game->mlx, game->mlx_win, game->map, game->images);
}

int hook_actions(int keycode, t_game *game)
{
    if (keycode == 97 || keycode == 65361)
        move_left(game);
    else if (keycode == 119 || keycode == 65362)
        move_up(game);
    else if (keycode == 100 || keycode == 65363)
        move_right(game);
    else if (keycode == 115 || keycode == 65364)
        move_down(game);
    printf("%i\n", game->map->x);
    return (0);
}