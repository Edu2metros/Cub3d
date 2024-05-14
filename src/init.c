/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:07:01 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/05/14 09:57:07 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_mlx_init(t_cub *cub)
{
	cub->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", FALSE);
	if (cub->mlx == NULL)
		exit_program(cub, "Error\nmlx_init failed\n");
	cub->img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	if (cub->img == NULL)
		exit_program(cub, "Error\nmlx_new_image failed\n");
}

static void	define_south(t_math *math)
{
	math->dir_x = 0;
	math->dir_y = 1;
	math->plane_x = 0.66;
	math->plane_y = 0;
}

void	define_variable_math(t_cub *cub)
{
	if (cub->info->dir == 'W')
	{
		cub->math->dir_x = -1;
		cub->math->dir_y = 0;
		cub->math->plane_x = 0;
		cub->math->plane_y = 0.66;
	}
	else if (cub->info->dir == 'E')
	{
		cub->math->dir_x = 1;
		cub->math->dir_y = 0;
		cub->math->plane_x = 0;
		cub->math->plane_y = -0.66;
	}
	else if (cub->info->dir == 'N')
	{
		cub->math->dir_x = 0;
		cub->math->dir_y = -1;
		cub->math->plane_x = -0.66;
		cub->math->plane_y = 0;
	}
	else
		define_south(cub->math);
}

t_cub	*init(void)
{
	t_cub		*cub;
	t_garbage	*garbage;

	garbage = NULL;
	cub = (t_cub *)calloc_gc(&garbage, 1, sizeof(t_cub));
	cub->garbage = garbage;
	cub->fd = 0;
	cub->err_flag = FALSE;
	*get_struct() = *cub;
	cub->info = (t_info *)calloc_gc(&cub->garbage, 1, sizeof(t_info));
	cub->info->cel = (int *)calloc_gc(&cub->garbage, 3, sizeof(int));
	cub->info->flo = (int *)calloc_gc(&cub->garbage, 3, sizeof(int));
	cub->math = (t_math *)calloc_gc(&cub->garbage, 1, sizeof(t_math));
	return (cub);
}
