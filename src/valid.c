#include "../includes/cub3d.h"

static void check_file(char *file, t_cub *cub)
{
    char *str;
    int fd;
    str = ft_substr(file, ft_strlen(file) - 4, 4);
    if(ft_strcmp(str, ".cub") != 0)
    {
        ft_printf_fd(STDERR_FILENO, "Error\nInvalid file extension\n");
        free(cub);
        free(str);
        exit(EXIT_FAILURE);
    }
    free(str);
    if((fd = open(file, O_RDONLY)) == -1)
    {
        ft_printf_fd(STDERR_FILENO, "Error\nInvalid file\n");
        free(cub);
        exit(EXIT_FAILURE);
    }
    cub->fd = fd;
}

// void map_validation(t_cub *cub)
// {
// }

void validation(int argc, char **argv, t_cub *cub)
{
    if(argc != 2)
    {
       ft_printf_fd(STDERR_FILENO, "Error\nInvalid number of arguments\n");
       exit(EXIT_FAILURE);
    }
    check_file(argv[1], cub);
    //map validation
}