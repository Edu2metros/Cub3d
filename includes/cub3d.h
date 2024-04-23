#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"

typedef struct s_cub
{
    int fd;
} t_cub;

t_cub *init(t_cub *cub);
void *ft_safe_malloc(size_t size);
t_cub *get_struct();
void validation(int argc, char **argv, t_cub *cub);

#endif