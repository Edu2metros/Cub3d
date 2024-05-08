/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:31:35 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/05/08 18:05:28 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_distance(t_math *m)
{
	if (m->ray_dir_x == 0)
		m->delta_dist_x = 1e30;
	else
		m->delta_dist_x = fabs(1 / m->ray_dir_x);
	if (m->ray_dir_y == 0)
		m->delta_dist_y = 1e30;
	else
		m->delta_dist_y = fabs(1 / m->ray_dir_y);
}

void	determinate_side_distance(t_math *m)
{
	double mapx = (double)(int)m->pos_x;
	double mapy = (double)(int)m->pos_y;

	if (m->ray_dir_x < 0)
	{
		m->step_x = -1;
		m->side_dist_x = (m->pos_x - mapx) * m->delta_dist_x;
	}
	else
	{
		m->step_x = 1;
		m->side_dist_x = (mapx + 1.0 - m->pos_x) * m->delta_dist_x;
	}
	if (m->ray_dir_y < 0)
	{
		m->step_y = -1;
		m->side_dist_y = (m->pos_y - mapy) * m->delta_dist_y;
	}
	else
	{
		m->step_y = 1;
		m->side_dist_y = (mapy + 1.0 - m->pos_y) * m->delta_dist_y;
	}
}

int wall_hit(t_cub *cub, t_math *m)
{
	if(m->mapx < 0 || m->mapy < 0)
		return(TRUE);
	if(cub->vectors[m->mapy][m->mapx].type == WALL)
		return (TRUE);
	return (FALSE);
}

void wall_side(t_math *m, char type)
{
	if(type == 'x' && m->ray_dir_x > 0)
		m->side = EA;
	else if(type == 'x' && m->ray_dir_x <= 0)
		m->side = WE;
	else if(type == 'y' && m->ray_dir_y > 0)
		m->side = SO;
	else if(type == 'y' && m->ray_dir_y <= 0)
		m->side = NO;
}

void	calculate_dda(t_cub *cub, t_math *m)
{
	while (TRUE)
	{
		if (m->side_dist_x < m->side_dist_y)
		{
			m->side_dist_x += m->delta_dist_x;
			m->mapx += m->step_x;
			wall_side(m, 'x');
		}
		else
		{
			m->side_dist_y += m->delta_dist_y;
			m->mapy += m->step_y;
			wall_side(m, 'y');
		}
		if(cub->vectors[m->mapy][m->mapx].type == WALL)
			break;
	}
}

int calculate_line_start(t_math *m)
{
	double wall_dist;
	int draw_start;
	int line_height;

	if(m->side == EA || m->side == WE)
		wall_dist = (m->side_dist_x - m->delta_dist_x);
	else
		wall_dist = (m->side_dist_y - m->delta_dist_y);
	line_height = (int)(HEIGHT / wall_dist);
	draw_start = -line_height / 2 + HEIGHT / 2;
	if(draw_start < 0)
		draw_start = 0;
	return (draw_start);
}

int calculate_line_end(t_math *m)
{
	double wall_dist;
	int draw_end;
	int line_height;
	
	if(m->side == EA || m->side == WE)
		wall_dist = (m->side_dist_x - m->delta_dist_x);
	else
		wall_dist = (m->side_dist_y - m->delta_dist_y);
	line_height = (int)(HEIGHT / wall_dist);
	m->line_height = line_height;
	draw_end = line_height / 2 + HEIGHT / 2;
	if(draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	return (draw_end);
}
