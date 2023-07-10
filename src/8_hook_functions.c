#include "so_long.h"

int hook_actions(int keycode, t_game *game)
{
    if (keycode == 97 || keycode == 65361)
        ft_printf("we're going left\n");
    else if (keycode == 119 || keycode == 65362)
        ft_printf("we're going up\n");
    else if (keycode == 100 || keycode == 65363)
        ft_printf("we're going right\n");
    else if (keycode == 115 || keycode == 65364)
        ft_printf("we're going down\n");
    printf("%i\n", game->map->x);
    return (0);
}