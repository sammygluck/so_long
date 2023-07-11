#include "so_long.h"

static void flood_fill(t_game *game, char *visited, int x, int y)
{
    int index;
    int width;
    char *map;

    map = game->map->map;
    width = game->map->x;
    index = (y - 1)  * width + (x - 1);
    ft_printf("map[i] %c\n", map[index]);
    ft_printf("index: %i\n", index);
    ft_printf("x: %i\n", x);
    ft_printf("y: %i\n", y);
    ft_printf("width: %i\n", width);
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
    int all_reachable;
    t_map print;

    all_reachable = 1;
    flood_map = ft_strdup(game->map->map);
    flood_fill(game, flood_map, game->player.x_pos, game->player.y_pos);
    if (get_char_count(flood_map, 'C') != 0)
        all_reachable = 0;
    if (get_char_count(flood_map, 'E') != 0)
        all_reachable = 0;
    print.map = flood_map;
    print.x = game->map->x;
    print.y = game->map->y;
    print_map(&print);
    free (flood_map);
    return (all_reachable);
}