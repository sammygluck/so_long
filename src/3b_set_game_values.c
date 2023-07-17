#include "so_long.h"

void set_player_start_position(t_game *game)
{
    int y;
    int x;
    t_map *map;
    t_player *player;

    player = &(game->player);
    player->moves = 0;
    map = game->map;
    y = 1;
    while(y <= map->y)
    {
        x = 1;
        while(x <= map->x)
        {
            if (get_value(map, x, y) == 'P')
            {
                player->x_pos = x;
                player->y_pos = y;
            }
            x++;
        }
        y++;
    }
}

void set_collectible_count(t_game *game)
{
    int y;
    int x;
    t_map *map;
    t_collectibles *collectibles;

    collectibles = &(game->collectibles);
    collectibles->collectible_count = 0;
    collectibles->found_collectibles = 0;
    game->exit_open = 0;
    map = game->map;
    y = 1;
    while(y <= map->y)
    {
        x = 1;
        while(x <= map->x)
        {
            if (get_value(map, x, y) == 'C')
                collectibles->collectible_count += 1;
            x++;
        }
        y++;
    }
}