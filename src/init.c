/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:07:01 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/05/14 08:13:43 by eddos-sa         ###   ########.fr       */
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

static void	init_variables_math(t_math *m)
{
	m->dir_x = -1;
	m->dir_y = 0;
	m->plane_x = 0;
	m->plane_y = 0.66;
	m->time = 0;
	m->side = 0;
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
	init_variables_math(cub->math);
	return (cub);
}
