/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:00:15 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/05/13 11:18:22 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_wallhit(t_vectors **vector, t_math *math, t_cub *cub, double x, double y)
{
	if(vector[(int)((x))][(int)(y)].type == WALL)	
		return (TRUE);
	return (FALSE);
}

// if (map[(int)cub->math->pos_y][pos_x] == '0'
// || map[(int)cub->math->pos_y][pos_x] == 'E')
// if (map[pos_y][(int)cub->math->pos_x] == '0'
// || map[pos_y][(int)cub->math->pos_x] == 'E')
// 	cub->math->pos_y += cub->math->dir_y * move_speed;
//   frame_time = (cub->math->time - cub->math->old_time) / 1000.0;
//   move_speed = frame_time * 5.0;

void	key_up(t_cub *cub, char **map)
{
	double	move_speed;
	int		pos_x;
	int		pos_y;
	int		steps = 0;
	int		max_steps = 1000;
	double	player_radius = 0.2;
	double	angle_step = M_PI / 4;
	double	angle = 0;

	move_speed = 0.10 / max_steps;
	while (steps < max_steps)
	{
		while (angle < 2 * M_PI)
		{
			pos_x = (int)(cub->math->pos_x + player_radius * cos(angle) + cub->math->dir_x * move_speed);
			pos_y = (int)(cub->math->pos_y + player_radius * sin(angle) + cub->math->dir_y * move_speed);
			if(is_wallhit(cub->vectors, cub->math, cub, pos_x, pos_y) == TRUE)
				return;
			angle += angle_step;
		}
		angle = 0;
		cub->math->pos_x += cub->math->dir_x * move_speed;
		cub->math->pos_y += cub->math->dir_y * move_speed;
		steps++;
	}
	draw_frame(cub);
}

void	key_down(t_cub *cub, char **map)
{
	double	move_speed;
	int		pos_x;
	int		pos_y;
	int		steps = 0;
	int		max_steps = 1000;
	double	player_radius = 0.2;
	double	angle_step = M_PI / 4;
	double	angle = 0;

	move_speed = 0.10 / max_steps;
	while (steps < max_steps)
	{
		while (angle < 2 * M_PI) 
		{
			pos_x = (int)(cub->math->pos_x + player_radius * cos(angle) - cub->math->dir_x * move_speed);
			pos_y = (int)(cub->math->pos_y + player_radius * sin(angle) - cub->math->dir_y * move_speed);
			if(is_wallhit(cub->vectors, cub->math, cub, pos_x, pos_y) == TRUE)
				return;
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
	double	frame_time;
	double	rot_speed;
	double	old_dir_x;
	double	old_plane_x;

	frame_time = (cub->math->time - cub->math->old_time) / 1000.0;
	//   rot_speed = frame_time * 3.0;
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
	double	frame_time;
	double	rot_speed;
	double	old_dir_x;
	double	old_plane_x;

	frame_time = (cub->math->time - cub->math->old_time) / 1000.0;
	rot_speed = frame_time * 3.0;
	//   rot_speed = 1.0;
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
	t_cub *cub = (t_cub *)arg;

	if (mlx_is_key_down(cub->mlx, MLX_KEY_UP))
		key_up(cub, cub->info->map);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_DOWN))
		key_down(cub, cub->info->map);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
		key_right(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
		key_left(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx);
}