#include "so_long.h"

int print_map(t_map *map)
{
    int y;
    int x;

    y = 1;

    while(y <= map->y)
    {
        x = 1;
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