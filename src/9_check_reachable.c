#include "so_long.h"

static void flood_fill(t_game *game, char *visited, int x, int y)
{
    int index;
    int width;
    char *map;

    map = game->map->map;
    width = game->map->y;
    index = y * width + x;

    if (map[index] == '1' || visited[index] == 't')
        return ;

    visited[index] = 't';

    flood_fill(game, visited, x + 1, y);
    flood_fill(game, visited, x - 1, y);
    flood_fill(game, visited, x, y + 1);
    flood_fill(game, visited, x, y - 1);
}

int check_all_reachable(t_game *game)
{
    char *flood_map;
    char *map;
    int all_reachable;
    int i;

    all_reachable = 1;
    flood_map = ft_strdup(game->map->map);
    flood_fill(game, flood_map, game->player.x_pos, game->player.y_pos);
    if (get_char_count(flood_map, 'C') != 0)
        all_reachable = 0;
    if (get_char_count(flood_map, 'E') != 0)
        all_reachable = 0;
    free (flood_map);
    return (all_reachable);
}