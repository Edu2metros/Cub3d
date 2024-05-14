/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:22:18 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/05/14 08:28:49 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	update_side_hit(t_math *m, char type)
{
	if (type == 'x' && m->ray_dir_x > 0)
		m->side_ray_hit = EA;
	else if (type == 'x' && m->ray_dir_x <= 0)
		m->side_ray_hit = WE;
	else if (type == 'y' && m->ray_dir_y > 0)
		m->side_ray_hit = SO;
	else if (type == 'y' && m->ray_dir_y <= 0)
		m->side_ray_hit = NO;
}

void	init_variables_paint(t_math *m, int x)
{
	m->camera_x = 2 * x / (double)WIDTH - 1;
	m->ray_dir_x = m->dir_x + m->camera_x * m->plane_x;
	m->ray_dir_y = m->dir_y + m->camera_x * m->plane_y;
	m->mapx = (int)m->pos_x;
	m->mapy = (int)m->pos_y;
}

mlx_texture_t	*get_texture(t_math *m, t_cub *cub)
{
	if (m->side_ray_hit == NO)
		return (cub->info->no);
	else if (m->side_ray_hit == SO)
		return (cub->info->so);
	else if (m->side_ray_hit == WE)
		return (cub->info->we);
	else
		return (cub->info->ea);
}

uint32_t	get_pixel(mlx_texture_t *texture, int texx, int texy)
{
	int		index;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	index = (texy * texture->width + texx) * texture->bytes_per_pixel;
	r = texture->pixels[index];
	g = texture->pixels[index + 1];
	b = texture->pixels[index + 2];
	a = texture->pixels[index + 3];
	return (ft_pixel(r, g, b, a));
}
