/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:34:24 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/05/08 15:51:32 by eddos-sa         ###   ########.fr       */
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

static void	draw_line(t_cub *cub, t_math *m, int x)
{
	int			draw_start;
	int			draw_end;
	uint32_t	color;

	draw_start = calculate_line_start(m);
	draw_end = calculate_line_end(m);
	if(wall_hit(cub, m) == TRUE)
		color = GREEN;
	// if (cub->info->map[m->mapy][m->mapx] == '1')
	// 	color = GREEN;
	while (draw_start < draw_end)
	{
		mlx_put_pixel(cub->img, x, draw_start, color);
		draw_start++;
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

void running2(t_cub *cub)
{
	for(int y = HEIGHT / 2 + 1; y < HEIGHT; ++y)
	{
		float rayDirX0 = cub->math->dir_x - cub->math->plane_x;
		float rayDirY0 = cub->math->dir_y - cub->math->plane_y;
		float rayDirX1 = cub->math->dir_x + cub->math->plane_x;
		float rayDirY1 = cub->math->dir_y + cub->math->plane_y;
		int p = y - HEIGHT / 2;
		float posZ = 0.5 * HEIGHT;
		float rowDistance = posZ / p;
		float floorStepX = rowDistance * (rayDirX1 - rayDirX0) / WIDTH;
		float floorStepY = rowDistance * (rayDirY1 - rayDirY0) / WIDTH;
		float floorX = cub->math->pos_x + rowDistance * rayDirX0;
		float floorY = cub->math->pos_y + rowDistance * rayDirY0;
		for(int x = 0; x < WIDTH; ++x)
		{
			int cellX = (int)(floorX);
			int cellY = (int)(floorY);
			int tx = (int)(64 * (floorX - cellX)) & (64 - 1);
			int ty = (int)(64 * (floorY - cellY)) & (64 - 1);
			floorX += floorStepX;
			floorY += floorStepY;
			int *rgb = cub->info->flo;
			uint32_t color = ft_pixel(rgb[0], rgb[1], rgb[2], 255);
			mlx_put_pixel(cub->img, x, y, color);
			rgb = cub->info->cel;
			color = ft_pixel(rgb[0], rgb[1], rgb[2], 255);
			mlx_put_pixel(cub->img, x, HEIGHT - y - 1, color);
		}
	}
	for(int x = 0; x < WIDTH; x++)
	{
		double cameraX = 2 * x / (double)WIDTH - 1;
		double rayDirX = cub->math->dir_x + cub->math->plane_x * cameraX;
		double rayDirY = cub->math->dir_y + cub->math->plane_y * cameraX;

		int mapX = (int)cub->math->pos_x;
		int mapY = (int)cub->math->pos_y;
		double sideDistX;
		double sideDistY;

		double deltadistx;
		double deltadisty;
		double perpwalldist;
		if(rayDirX == 0)
			deltadistx = 1e30;
		else
			deltadistx = fabs(1 / rayDirX);
		if(rayDirY == 0)
			deltadisty = 1e30;
		else
			deltadisty = fabs(1 / rayDirY);
		int stepX;
		int stepY;
		int hit = 0;
		int side;

		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (cub->math->pos_x - mapX) * deltadistx;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - cub->math->pos_x) * deltadistx;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (cub->math->pos_y - mapY) * deltadisty;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - cub->math->pos_y) * deltadisty;
		}
		while(hit == 0)
		{
			if(sideDistX < sideDistY)
			{
				sideDistX += deltadistx;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltadisty;
				mapY += stepY;
				side = 1;
			}
			if(cub->info->map[mapY][mapX] == '1')
				hit = 1;
		}
		if(side == 0)
			perpwalldist = (mapX - cub->math->pos_x + (1 - stepX) / 2) / rayDirX;
		else
			perpwalldist = (mapY - cub->math->pos_y + (1 - stepY) / 2) / rayDirY;
		int lineHeight = (int)(HEIGHT / perpwalldist);
		int drawStart = -lineHeight / 2 + HEIGHT / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + HEIGHT / 2;
		if(drawEnd >= HEIGHT)
			drawEnd = HEIGHT - 1;
		char texNum = cub->info->map[mapY][mapX];
		double wallX;
		if(side == 0)
			wallX = cub->math->pos_y + perpwalldist * rayDirY;
		else
			wallX = cub->math->pos_x + perpwalldist * rayDirX;
		wallX -= floor((wallX));
		int texX = (int)(wallX * (double)(64));
		if(side == 0 && rayDirX > 0)
			texX = 64 - texX - 1;
		if(side == 1 && rayDirY < 0)
			texX = 64 - texX - 1;
		double step = 1.0 * 64 / lineHeight;
		double texPos = (drawStart - HEIGHT / 2 + lineHeight / 2) * step;
		mlx_texture_t *tex;
		mlx_image_t *img;
		if(texNum == '1')
			tex = cub->info->no;
		img = mlx_new_image(cub->mlx, tex->width, tex->height);
	}
	mlx_image_to_window(cub->mlx, cub->img, 0, 0);
}