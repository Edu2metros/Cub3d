#include "../../includes/cub3d.h"

int		worldMap[24][24] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 2, 2, 2,
			2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 2,
			0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0,
			0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 1}, {1, 0, 0,
			0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1,
			0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0,
			1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 1},
						{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 4, 4, 4, 4, 4, 4,
							4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
							{1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 1}, {1, 4, 0, 0, 0, 0, 5, 0, 4, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 4, 0,
							4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 1}, {1, 4, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 4, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
							1}, {1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0,
							0, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1,
							1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

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
	m->camera_x = 2 * x / (double)WIDTH - 1;
	m->ray_dir_x = m->dir_x + m->plane_x * m->camera_x;
	m->ray_dir_y = m->dir_y + m->plane_y * m->camera_x;
	m->mapx = (int)m->pos_x;
	m->mapy = (int)m->pos_y;
}

void	determinate_side_distance(t_cub *cub, t_math *m)
{
	if (m->ray_dir_x < 0)
	{
		m->step_x = -1;
		m->side_dist_x = (m->pos_x - m->mapx) * m->delta_dist_x;
	}
	else
	{
		m->step_x = 1;
		m->side_dist_x = (m->mapx + 1.0 - m->pos_x) * m->delta_dist_x;
	}
	if (m->ray_dir_y < 0)
	{
		m->step_y = -1;
		m->side_dist_y = (m->pos_y - m->mapy) * m->delta_dist_y;
	}
	else
	{
		m->step_y = 1;
		m->side_dist_y = (m->mapy + 1.0 - m->pos_y) * m->delta_dist_y;
	}
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
		if (worldMap[m->mapx][m->mapy] > 0)
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
	if (worldMap[m->mapx][m->mapy] == 1)
		color = 0xFF0000FFu;
	else
		color = 0xFFFF00FFu;
	while (draw_start < draw_end)
	{
		mlx_put_pixel(cub->img, x, draw_start, color);
		draw_start++;
	}
	mlx_image_to_window(cub->mlx, cub->img, 0, 0);
}

void	running(void *arg)
{
	t_cub	*cub;
	t_math	*m;
	int		x;

	cub = (t_cub *)arg;
	m = cub->math;
	m->pos_x = 22;
	m->pos_y = 12;
	m->plane_x = 0;
	m->plane_y = 0.66;
	m->dir_x = -1;
	m->dir_y = 0;
	x = 0;
	while (x < WIDTH)
	{
		variables_paint(cub, m, x);
		calculate_distance(cub, m);
		determinate_side_distance(cub, m);
		calculate_dda(cub, m);
		draw_line(cub, m, x);
		if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
			mlx_terminate(cub->mlx);
		x++;
	}
}
