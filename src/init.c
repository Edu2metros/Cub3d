#include "../includes/cub3d.h"

t_cub *get_struct(void)
{
    static t_cub cub;
    return(&cub);
}

t_cub *init(t_cub *cub)
{
    cub = (t_cub *)ft_safe_malloc(sizeof(t_cub));
    cub->fd = 0;
    cub->err_flag = FALSE;
    *get_struct() = *cub;
    return (cub);
}
