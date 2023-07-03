#include "so_long.h"

static void check_ber(char *ber_file)
{
    int length;

    length = ft_strlen(ber_file);
    if (length < 4 || ft_strncmp(&ber_file[length - 4], ".ber", 4) != 0)
    {
        ft_printf("Error\nPlease provide a .ber file as input");
        exit(EXIT_FAILURE);
    }
}

static void check_argc(int argc)
{
    if (argc != 2)
    {
        ft_printf("Error\nPlease provide only the .ber file as argument");
        exit(EXIT_FAILURE);
    }
}

void check_input(int argc, char **argv)
{
    check_argc(argc);
    check_ber(argv[1]);
}