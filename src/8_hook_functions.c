#include "so_long.h"


static void move_left(t_game *game)
{
    int x;
    int y;

    x = game->player.x_pos;
    y = game->player.y_pos;
    //can I go left
    if (get_value(game->map, x - 1, y) == '1')
        return ;
    else
        ft_printf("I can go left");
    //if I can, go left
}

int hook_actions(int keycode, t_game *game)
{
    if (keycode == 97 || keycode == 65361)
        move_left(game);
    else if (keycode == 119 || keycode == 65362)
        ft_printf("we're going up\n");
    else if (keycode == 100 || keycode == 65363)
        ft_printf("we're going right\n");
    else if (keycode == 115 || keycode == 65364)
        ft_printf("we're going down\n");
    printf("%i\n", game->map->x);
    return (0);
}