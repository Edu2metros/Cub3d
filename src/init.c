#include "../includes/cub3d.h"

t_cub *get_struct(void)
{
    static t_cub cub;
    return(&cub);
}

t_cub *init(void)
{
    t_cub *cub;
    t_garbage *garbage;
    garbage = NULL;
    cub = (t_cub *)malloc_garbage_collector(&garbage, sizeof(t_cub));
    cub->garbage = garbage;
    cub->fd = 0;
    cub->err_flag = FALSE;
    *get_struct() = *cub;
    return (cub);
}

