#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
    t_cub *cub;
    cub = (t_cub *)ft_safe_malloc(sizeof(t_cub));
    // cub = init(cub);
    validation(argc, argv, cub); 
    free(cub);
    //Cub3d function (entire project here)
    // finish
    return(EXIT_SUCCESS);
}