/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:00:15 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/05/25 16:47:40 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#define M_PI 3.14159265358979323846

void	replace_image(t_cub *cub)
{
	if (cub->img)
	{
		mlx_delete_image(cub->mlx, cub->img);
		cub->img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	}
}

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
}

void	key_left(t_cub *cub)
{
	double	rot_speed;
	double	old_dir_x;
	double	old_plane_x;
	double	cos_rot_speed;
	double	sin_rot_speed;

	rot_speed = 0.09;
	cos_rot_speed = cos(rot_speed);
	sin_rot_speed = sin(rot_speed);
	old_dir_x = cub->math->dir_x;
	cub->math->dir_x = cub->math->dir_x * cos_rot_speed - cub->math->dir_y
		* sin_rot_speed;
	cub->math->dir_y = old_dir_x * sin_rot_speed + cub->math->dir_y
		* cos_rot_speed;
	old_plane_x = cub->math->plane_x;
	cub->math->plane_x = cub->math->plane_x * cos_rot_speed
		- cub->math->plane_y * sin_rot_speed;
	cub->math->plane_y = old_plane_x * sin_rot_speed + cub->math->plane_y
		* cos_rot_speed;
}

void	keys(void *arg)
{	
	t_cub	*cub;

	cub = (t_cub *)arg;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_W))
		key_up(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_S))
		key_down(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
		key_right(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
		key_left(cub);
}
