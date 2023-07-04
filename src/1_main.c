#include "so_long.h"

int main(int argc, char **argv)
{
    t_map   *map;
    t_master data;
    
    check_input(argc, argv);
    map = malloc(sizeof (t_map));
    if (!map)
        ft_printf("error to be handled still");
    init_map(map->map);
    data.map = map;
    ft_printf("\n datamap: %s", data.map);
    //map_to_window();
}