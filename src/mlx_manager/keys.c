/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:00:15 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/05/14 11:00:39 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#define M_PI 3.14159265358979323846

void	key_up(t_cub *cub)
{
	double	move_speed;
	int		steps;
	double	angle_step;
	double	angle;

	steps = 0;
	angle_step = M_PI / 4;
	angle = 0;
	move_speed = 0.10 / MAX_STEPS;
	while (steps < MAX_STEPS)
	{
		while (angle < 2 * M_PI)
		{
			if (walk_up(cub, angle, move_speed) == TRUE)
				return ;
			angle += angle_step;
		}
		angle = 0;
		cub->math->pos_x += cub->math->dir_x * move_speed;
		cub->math->pos_y += cub->math->dir_y * move_speed;
		steps++;
	}
	draw_frame(cub);
}

void	key_down(t_cub *cub)
{
	double	move_speed;
	int		steps;
	double	angle_step;
	double	angle;

	steps = 0;
	angle_step = M_PI / 4;
	angle = 0;
	move_speed = 0.10 / MAX_STEPS;
	while (steps < MAX_STEPS)
	{
		while (angle < 2 * M_PI)
		{
			if (walk_down(cub, angle, move_speed) == TRUE)
				return ;
			angle += angle_step;
		}
		angle = 0;
		cub->math->pos_x -= cub->math->dir_x * move_speed;
		cub->math->pos_y -= cub->math->dir_y * move_speed;
		steps++;
	}
	draw_frame(cub);
}

void	key_right(t_cub *cub)
{
	double	rot_speed;
	double	old_dir_x;
	double	old_plane_x;

	rot_speed = 0.09;
	old_dir_x = cub->math->dir_x;
	cub->math->dir_x = cub->math->dir_x * cos(-rot_speed) - cub->math->dir_y
		* sin(-rot_speed);
	cub->math->dir_y = old_dir_x * sin(-rot_speed) + cub->math->dir_y
		* cos(-rot_speed);
	old_plane_x = cub->math->plane_x;
	cub->math->plane_x = cub->math->plane_x * cos(-rot_speed)
		- cub->math->plane_y * sin(-rot_speed);
	cub->math->plane_y = old_plane_x * sin(-rot_speed) + cub->math->plane_y
		* cos(-rot_speed);
	draw_frame(cub);
}

void	key_left(t_cub *cub)
{
	double	rot_speed;
	double	old_dir_x;
	double	old_plane_x;

	rot_speed = 0.09;
	old_dir_x = cub->math->dir_x;
	cub->math->dir_x = cub->math->dir_x * cos(rot_speed) - cub->math->dir_y
		* sin(rot_speed);
	cub->math->dir_y = old_dir_x * sin(rot_speed) + cub->math->dir_y
		* cos(rot_speed);
	old_plane_x = cub->math->plane_x;
	cub->math->plane_x = cub->math->plane_x * cos(rot_speed)
		- cub->math->plane_y * sin(rot_speed);
	cub->math->plane_y = old_plane_x * sin(rot_speed) + cub->math->plane_y
		* cos(rot_speed);
	draw_frame(cub);
}

void	keys(void *arg)
{
	t_cub	*cub;

	cub = (t_cub *)arg;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_UP))
		key_up(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_DOWN))
		key_down(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
		key_right(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
		key_left(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx);
}
