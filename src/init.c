#include "../includes/cub3d.h"

t_cub *init(t_cub *cub)
{
    cub = (t_cub *)ft_safe_malloc(sizeof(t_cub));
    cub->fd = 0;
    cub->err_flag = FALSE;
    return (cub);
}

