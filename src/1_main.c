#include "so_long.h"

int main(int argc, char **argv)
{
    t_map   *map;
    
    check_input(argc, argv);
    map = malloc(sizeof (t_map));
    if (!map)
        ft_printf("error to be handled still");
    init_map(map);
}