/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:00:15 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/05/07 16:08:51 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void key_up(t_cub *cub)
{
  double frame_time;
  double move_speed;
  int pos_x;
  int pos_y;
  
  frame_time = (cub->math->time - cub->math->old_time) / 1000.0;
  move_speed = frame_time * 5.0;
  pos_x = (int)cub->math->pos_x + (int)cub->math->dir_x * move_speed;
  pos_y = (int)cub->math->pos_y + (int)cub->math->dir_y * move_speed;
  if(cub->info->map[pos_x][(int)cub->math->pos_y] == '0' || cub->info->map[pos_x][(int)cub->math->pos_y] == 'E')
    cub->math->pos_x += cub->math->dir_x * move_speed;
  if(cub->info->map[(int)cub->math->pos_x][pos_y] == '0' || cub->info->map[(int)cub->math->pos_x][pos_y] == 'E')
    cub->math->pos_y += cub->math->dir_y * move_speed;
  draw_frame(cub);
}

void key_down(t_cub *cub)
{
  double frame_time;
  double move_speed;
  int pos_x;
  int pos_y;
  
  frame_time = (cub->math->time - cub->math->old_time) / 1000.0;
  move_speed = frame_time * 5.0;
  pos_x = (int)cub->math->pos_x - (int)cub->math->dir_x * move_speed;
  pos_y = (int)cub->math->pos_y - (int)cub->math->dir_y * move_speed;
  if(cub->info->map[pos_x][(int)cub->math->pos_y] == '0' || cub->info->map[pos_x][(int)cub->math->pos_y] == 'E')
    cub->math->pos_x -= cub->math->dir_x * move_speed;
  if(cub->info->map[(int)cub->math->pos_x][pos_y] == '0' || cub->info->map[(int)cub->math->pos_x][pos_y] == 'E')
    cub->math->pos_y -= cub->math->dir_y * move_speed;
  draw_frame(cub);
}

void key_right(t_cub *cub)
{
  double frame_time;
  double rot_speed;
  double old_dir_x;
  double old_plane_x;

  frame_time = (cub->math->time - cub->math->old_time) / 1000.0;
  rot_speed = frame_time * 3.0;
  old_dir_x = cub->math->dir_x;
  cub->math->dir_x = cub->math->dir_x * cos(-rot_speed) - cub->math->dir_y * sin(-rot_speed);
  cub->math->dir_y = old_dir_x * sin(-rot_speed) + cub->math->dir_y * cos(-rot_speed);
  old_plane_x = cub->math->plane_x;
  cub->math->plane_x = cub->math->plane_x * cos(-rot_speed) - cub->math->plane_y * sin(-rot_speed);
  cub->math->plane_y = old_plane_x * sin(-rot_speed) + cub->math->plane_y * cos(-rot_speed);
  draw_frame(cub);
}

void key_left(t_cub *cub)
{
  double frame_time;
  double rot_speed;
  double old_dir_x;
  double old_plane_x;

  frame_time = (cub->math->time - cub->math->old_time) / 1000.0;
  rot_speed = frame_time * 3.0;
  old_dir_x = cub->math->dir_x;
  cub->math->dir_x = cub->math->dir_x * cos(rot_speed) - cub->math->dir_y * sin(rot_speed);
  cub->math->dir_y = old_dir_x * sin(rot_speed) + cub->math->dir_y * cos(rot_speed);
  old_plane_x = cub->math->plane_x;
  cub->math->plane_x = cub->math->plane_x * cos(rot_speed) - cub->math->plane_y * sin(rot_speed);
  cub->math->plane_y = old_plane_x * sin(rot_speed) + cub->math->plane_y * cos(rot_speed);
  draw_frame(cub);
}

void keys(void *arg)
{
  t_cub *cub = (t_cub *)arg;

  if(mlx_is_key_down(cub->mlx, MLX_KEY_UP))
    key_up(cub);
  if(mlx_is_key_down(cub->mlx, MLX_KEY_DOWN))
    key_down(cub);
  if(mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
    key_right(cub);
  if(mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
    key_left(cub);
  if(mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
    mlx_terminate(cub->mlx);
}