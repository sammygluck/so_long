#include "so_long.h"

int validate_borders(t_map *map)
{
    int y;
    int x;

    y = 1;
    x = 1;

    while(y <= map->y)
    {
        while(x <= map->x)
        {
            ft_printf("%c", get_value(map, x, y));
            x++;
        }
        y++;
        ft_printf("\n");
    }
    return (1);
}