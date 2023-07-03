#include "so_long.h"

typedef struct s_map
{
    char *map;
    int x;
    int y;
} t_map;

//is this the optimal solution?
void strip_newline(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] == '\n')
            line[i] = '\0';
        i++;
    }
}

void add_line_to_map(char *line, t_map *map)
{
    //we also have to strip the newline characters at the end
    strip_newline(line);

    //first line 
    //we don't need to join to any previous lines
    //what is the x value
    if (map->y == 0)
    {
        map->map = malloc(ft_strlen(line));
        //make sure we deal correctly with the error
        if (!(map->map))
            return (0);
        //check for the length of the line
        map->x = ft_strlen(line);
        //validate the length (make sure it's the minimum required length) at least 4 if not more

        //copy the string to the map->map stuff 
        map->map = ft_strdup(line);
         //should we free line now or in the parent of this function (current implemenation: parent at the end)
    }

    //other lines
    //check if each x value is the same as first
    // join to the already existing string
    
}


void    init_map()
{
    t_map   *map;
    char *line;
    int fd;

    fd = open("map.ber", O_RDONLY);
    //error check
    map = malloc(sizeof (t_map));
    if (!map)
        ft_printf("error to be handled still");
    //might need to find a better place for this potentially:
    map->x = 0;
    map->y = 0;
    
    //call gnl until end
    //for every call we'll join unto the previous string
    //we also have to differentiate between the first, last and rest of the strings
    while (1)
    {
       
        line = get_next_line(fd);
        if (!line)
            break;
        add_line_to_map(line, map);
        free(line);
        //make sure to add to the y value each time
        map->y += 1;
    }
    ft_printf("%s", map->map);
}

int main(int argc, char **argv)
{
    //to adjust afterwards
    (void) argc;
    (void) argv;

    init_map();
}