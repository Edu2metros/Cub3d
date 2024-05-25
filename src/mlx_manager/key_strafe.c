/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_strafe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:22:13 by nprudenc          #+#    #+#             */
/*   Updated: 2024/05/25 17:25:05 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	key_right_strafe(t_cub *cub)
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
			if (walk_right(cub, angle, move_speed) == TRUE)
				return ;
			angle += angle_step;
		}
		angle = 0;
		cub->math->pos_x += cub->math->plane_x * move_speed;
		cub->math->pos_y += cub->math->plane_y * move_speed;
		steps++;
	}
}

void	key_left_strafe(t_cub *cub)
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
			if (walk_left(cub, angle, move_speed) == TRUE)
				return ;
			angle += angle_step;
		}
		angle = 0;
		cub->math->pos_x -= cub->math->plane_x * move_speed;
		cub->math->pos_y -= cub->math->plane_y * move_speed;
		steps++;
	}
}
