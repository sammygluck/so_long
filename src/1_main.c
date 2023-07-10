#include "so_long.h"

int main(int argc, char **argv)
{
    t_map   *map;
    t_game game;
    
    check_input(argc, argv);
    map = malloc(sizeof (t_map));
    if (!map)
        ft_printf("error to be handled still");
    init_map(map);
    game.map = map;
    map_to_window(&game);
    ft_printf("\ndatamap: %s", game.map->map);
    //map_to_window();
}