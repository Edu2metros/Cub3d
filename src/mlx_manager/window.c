#include "../../includes/cub3d.h"

double	get_player_pos(t_vectors **vectors, char type)
{
	int	x;
	int	y;

	y = 0;
	while (vectors[y])
	{
		x = 0;
		while (vectors[y][x].type)
		{
			if (vectors[y][x].type == PLAYER)
			{
				if (type == 'x')
					return (vectors[y][x].x);
				else if (type == 'y')
					return (vectors[y][x].y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

mlx_t	*init_window(t_vectors **vectors)
{
	mlx_t		*mlx;
	mlx_image_t	*paint;

	// t_vectors *player;
	mlx = mlx_init(1920, 1080, "Enemies of math", FALSE);
	paint = mlx_new_image(mlx, mlx->width, mlx->height);
	(void)vectors;
	// get_player_pos(vectors);
	// player = get_player_pos(vectors);
	// printf("playerY: %i; playerX: %i\n", player->y, player->x);
	// for (int i = 50; i; i--)
	// 	mlx_put_pixel(paint, player->x++, player->y++, 0XFFFFFF);
	mlx_image_to_window(mlx, paint, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (mlx);
}

void	calculate_distance(t_cub *cub, t_math *m)
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

void	variables_paint(t_cub *cub, t_math *m, int x)
{
	m->camera_x = 2 * x / (WIDTH - 1.0) - 1.0;
	m->ray_dir_x = m->dir_x + m->camera_x * m->plane_x;
	m->ray_dir_y = m->dir_y + m->camera_x * m->plane_y;
	m->mapx = (int)m->pos_x;
	m->mapy = (int)m->pos_y;
}

void	determinate_side_distance(t_cub *cub, t_math *m)
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

int is_hit(t_cub *cub, t_math *m)
{
	if(m->mapx < 0 || m->mapy < 0)
		return (1);
	if (cub->info->map[m->mapx][m->mapy] && cub->info->map[m->mapx][m->mapy] == '1')
		return (1);
	return (0);
}

void	calculate_dda(t_cub *cub, t_math *m)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (m->side_dist_x < m->side_dist_y)
		{
			m->side_dist_x += m->delta_dist_x;
			m->mapx += m->step_x;
			m->side = 0;
		}
		else
		{
			m->side_dist_y += m->delta_dist_y;
			m->mapy += m->step_y;
			m->side = 1;
		}
		if (cub->info->map[m->mapy][m->mapx] == '1')
			hit = 1;
	}
}

int	calculate_line(t_cub *cub, t_math *m, char type)
{
	double	wall_dist;
	int		draw_start;
	int		draw_end;
	int		line_height;

	if (m->side == 0)
		wall_dist = (m->side_dist_x - m->delta_dist_x);
	else
		wall_dist = (m->side_dist_y - m->delta_dist_y);
	line_height = (int)(HEIGHT / wall_dist);
	draw_start = -line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	if (type == 's')
		return (draw_start);
	return (draw_end);
}

void	draw_line(t_cub *cub, t_math *m, int x)
{
	int			draw_start;
	int			draw_end;
	uint32_t	color;

	draw_start = calculate_line(cub, m, 's');
	draw_end = calculate_line(cub, m, 'e');
	if (cub->info->map[m->mapy][m->mapx] == '1')
		color = GREEN;
	else
		color = BLACK;
	while (draw_start < draw_end)
	{
		mlx_put_pixel(cub->img, x, draw_start, color);
		draw_start++;
	}
	mlx_image_to_window(cub->mlx, cub->img, 0, 0);
}

void update_time(t_math *m)
{
	m->old_time = m->time;
	m->time = mlx_get_time();
}

void	running(t_cub *cub)
{
	t_math	*m;
	m = cub->math;
	int x;
	x = 0;
	while (x < WIDTH)
	{
		variables_paint(cub, m, x);
		calculate_distance(cub, m);
		determinate_side_distance(cub, m);
		calculate_dda(cub, m);
		draw_line(cub, m, x);
		x++;
	}
	update_time(m);
}
int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
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