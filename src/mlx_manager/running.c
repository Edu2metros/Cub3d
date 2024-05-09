/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:34:24 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/05/09 19:42:49 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_variables_paint(t_math *m, int x)
{
	m->camera_x = 2 * x / (WIDTH - 1.0) - 1.0;
	m->ray_dir_x = m->dir_x + m->camera_x * m->plane_x;
	m->ray_dir_y = m->dir_y + m->camera_x * m->plane_y;
	m->mapx = (int)m->pos_x;
	m->mapy = (int)m->pos_y;
}

mlx_texture_t *get_texture(t_math *m, t_cub *cub)
{
	if(m->side == NO)
		return(cub->info->no);
	else if(m->side == SO)
		return(cub->info->so);
	else if(m->side == WE)
		return(cub->info->we);
	else
		return(cub->info->ea);
}

/* static void	draw_line(t_cub *cub, t_math *m, int x)
{
	int			draw_start;
	int			draw_end;
	uint32_t	color;
	mlx_texture_t *texture;

	draw_start = calculate_line_start(m);
	draw_end = calculate_line_end(m);
	texture = get_texture(m, cub);
	if (cub->info->map[m->mapy][m->mapx] == '1')
		color = GREEN;
	while (draw_start < draw_end)
	{
		mlx_put_pixel(cub->img, x, draw_start, color);
		draw_start++;
	}
} */

/* uint32_t get_pixel(mlx_texture_t *texture, t_math *m, int draw_start)
{
	uint32_t pixel;
	if(m->side == NO)
		pixel = GREEN;
	else if(m->side == SO)
		pixel = RED;
	else if(m->side == WE)
		pixel = BLUE;
	else
		pixel = YELLOW;	
	return(pixel);
} */

int	get_pixel(mlx_texture_t *texture, int texy, int texx)
{
	uint8_t *pixel;
	uint8_t alpha;
	uint8_t r;
	uint8_t g;
	uint8_t b;
	
	pixel = (uint8_t *)&texture->pixels[((texy * texture->width) + texx) * 4];
	r = pixel[0];
	g = pixel[1];
	b = pixel[2];
	alpha = pixel[3];
	return (ft_pixel(r, g, b, alpha));
}

void draw_line(t_cub *cub, t_math *m, int x)
{
	int draw_start;
	int draw_end;
	uint32_t color;
	mlx_texture_t *texture;
	
	draw_start = calculate_line_start(m);
	draw_end = calculate_line_end(m);
	texture = get_texture(m, cub);
	
	// LO DEV
	double wallX;
	if(m->side == NO || m->side == SO)
		wallX = m->pos_y + m->wall_dist * m->ray_dir_y;
	else
		wallX = m->pos_x + m->wall_dist * m->ray_dir_x;
	wallX -= floor(wallX);
	int texx = (int)(wallX * (double)texture->width);
	if(m->side == 0 || m->ray_dir_x > 0)
		texx = texture->width - texx - 1;
	if(m->side == 1 || m->ray_dir_y < 0)
		texx = texture->width - texx - 1;
	double step = 1.0 * texture->height / m->line_height;
	double texPos = (draw_start - HEIGHT / 2 + m->line_height / 2) * step;
	int y = draw_start;
	int buffer[600];
	while(y < draw_end)
	{
		int texy = (int)texPos & (texture->height - 1);
		texPos += step;
		uint32_t color = get_pixel(texture, texy, texx); 
		buffer[y] = color;
		y++;
	}
	y = draw_start;
	while(y < draw_end)
	{
		mlx_put_pixel(cub->img, x, y, buffer[y]);
		y++;
	}
}

float calculate_raydir(double dir, double plane, char type)
{
	if(type == '-')
		return (dir - plane);
	else
		return (dir + plane);
}

void draw_cel_floor(t_cub *cub, t_math *m)
{
	uint32_t color_cel;
	uint32_t color_floor;
	int y;
	int x;
	color_cel = ft_pixel(cub->info->cel[0], cub->info->cel[1], cub->info->cel[2], 255);
	color_floor = ft_pixel(cub->info->flo[0], cub->info->flo[1], cub->info->flo[2], 255);

	y = HEIGHT / 2 + 1;
	while(y < HEIGHT)
	{
		x = 0;
		while(x < WIDTH)
		{
			mlx_put_pixel(cub->img, x, y, color_cel);
			mlx_put_pixel(cub->img, x, HEIGHT - y - 1, color_floor);
			x++;
		}
		y++;
	}
}

void	draw_frame(t_cub *cub)
{
	t_math	*m;
	int x;
	m = cub->math;
	x = 0;

	draw_cel_floor(cub, m);
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
	update_time(m);
}
