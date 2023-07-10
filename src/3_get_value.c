#include "so_long.h"

char get_value(t_map *map, int x, int y)
{
    char value;
    int index;

    //what's if it's zero or less??
    index = (y - 1) * map->x + (x - 1);
    value = map->map[index];
    return (value);
}

void set_value(t_map *map, char value, int x, int y)
{
    int index;

    index = (y - 1) * map->x + (x - 1);
    map->map[index] = value;
}

void set_player_start_position(t_game *game)
{
    int y;
    int x;
    t_map *map;
    t_player *player;

    player = &(game->player);
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