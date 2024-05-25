/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:34:24 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/05/25 17:40:05 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	define_tex_x(t_math *m, mlx_texture_t *texture)
{
	double	wallx;
	int		tex_x;

	if (m->side == 0)
	{
		m->wall_dist = (m->side_dist_x - m->delta_dist_x);
		wallx = m->pos_y + m->wall_dist * m->ray_dir_y;
	}
	else
	{
		m->wall_dist = (m->side_dist_y - m->delta_dist_y);
		wallx = m->pos_x + m->wall_dist * m->ray_dir_x;
	}
	wallx -= floor(wallx);
	tex_x = (int)(wallx * (double)texture->width);
	if (m->side == 0 && m->ray_dir_x > 0)
		tex_x = texture->width - tex_x - 1;
	if (m->side == 1 && m->ray_dir_y < 0)
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}

void	draw_line(t_cub *cub, t_math *m, int x)
{
	mlx_texture_t	*texture;
	int				draw_start;
	int				draw_end;
	int				tex_x;
	int				tex_y;

	draw_start = calculate_line_start(m);
	draw_end = calculate_line_end(m);
	texture = get_texture(m, cub);
	tex_x = define_tex_x(m, texture);
	m->step_line = (1.0 * texture->height / m->line_height);
	m->tex_pos = (draw_start - HEIGHT / 2 + m->line_height / 2) * m->step_line;
	while (draw_start < draw_end && draw_start < HEIGHT)
	{
		tex_y = (int)m->tex_pos & (texture->height - 1);
		m->tex_pos += m->step_line;
		mlx_put_pixel(cub->img, x, draw_start, get_pixel(texture, tex_x,
				tex_y));
		draw_start++;
	}
}

static void	draw_background(t_cub *cub)
{
	uint32_t	color_cel;
	uint32_t	color_floor;
	int			y;
	int			x;

	color_cel = ft_pixel(cub->info->cel[0], cub->info->cel[1],
			cub->info->cel[2], 255);
	color_floor = ft_pixel(cub->info->flo[0], cub->info->flo[1],
			cub->info->flo[2], 255);
	y = HEIGHT / 2 + 1;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(cub->img, x, y, color_floor);
			mlx_put_pixel(cub->img, x, HEIGHT - y - 1, color_cel);
			x++;
		}
		y++;
	}
}

static void	replace_img(t_cub *cub)
{
	if (cub->img)
	{
		mlx_delete_image(cub->mlx, cub->img);
		cub->img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	}
}

void	draw_frame(void *p)
{
	t_cub	*cub;
	t_math	*m;
	int		x;

	cub = (t_cub *)p;
	m = cub->math;
	x = 0;
	replace_img(cub);
	draw_background(cub);
	while (x < WIDTH)
	{
		init_variables_paint(m, x);
		calculate_distance(m);
		determinate_side_distance(m);
		calculate_dda(cub, m);
		draw_line(cub, m, x);
		x++;
	}
	mlx_image_to_window(cub->mlx, cub->img, 0, 0);
}
