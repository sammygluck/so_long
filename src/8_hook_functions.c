#include "so_long.h"

int hook_actions(int keycode, t_game *game)
{
    printf("%i\n", keycode);
    printf("%i\n", game->map->x);
    printf("hello it works");
    return (0);
}