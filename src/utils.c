#include "../includes/cub3d.h"

t_cub *get_struct()
{
    static t_cub cub;
    return (&cub);
}

void *ft_safe_malloc(size_t size)
{
    void *ptr;
    ptr = malloc(size);
    if(ptr == NULL)
    {
        ft_printf_fd(STDERR_FILENO, "Error\nMalloc failed\n");
        exit(EXIT_FAILURE);
    }
    return (ptr);
}

