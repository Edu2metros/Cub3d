#include "../../includes/cub3d.h"

t_vectors *get_player_pos(t_vectors **vectors)
{
	int	x;
	int	y;

	y = -1;
	while (vectors[++y])
	{
		x = -1;
		while (vectors[++x])
		{
			if (vectors[y][x].type == PLAYER)
				printf("PLAYER\n");
		}
	}
	return (NULL);
}

mlx_t	*init_window(t_vectors **vectors)
{
	mlx_t	*mlx;
	mlx_image_t *paint;
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