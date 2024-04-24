#include "../includes/cub3d.h"

t_cub *init(t_cub *cub)
{
    cub = (t_cub *)ft_safe_malloc(sizeof(t_cub));
    cub->fd = 0;
    cub->clr_flag = 1;
    return (cub);
}

