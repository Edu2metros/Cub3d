#include "../../includes/cub3d.h"

void	free_vectors(t_vectors **vectors);

static int	find_max_x(char **map)
{
	int	i;
	int	result;
	int	counter;

	i = 0;
	result = 0;
	while (map[i])
	{
		counter = ft_strlen(map[i]);
		if (counter > result)
			result = counter;
		i++;
	}
	return (result);
}

static void	assign_types(char type, t_vectors *vectors, t_math *math)
{
	if (ft_isspace(type))
		vectors->type = SPACE;
	else if (type == '0')
		vectors->type = FLOOR;
	else if (type == '1')
		vectors->type = WALL;
	else
	{
		vectors->type = PLAYER;
		math->pos_x = vectors->x;
		math->pos_y = vectors->y;
	}
}

void define_vectors(char **map, t_cub *cub)
{
	int x;
	int y;
	int max_x;
	x = -1;

	max_x = find_max_x(map);
	while(map[++x])
		;
	cub->vectors = calloc_garbage_collector(&cub->garbage, x + 1, sizeof(t_vectors *));
	x = -1;
	while(map[++x])
	{
		cub->vectors[x] = calloc_garbage_collector(&cub->garbage, max_x, sizeof(t_vectors));
		y = -1;
		while(map[x][++y])
		{
			if(map[x][y] != '\n')
			{
				cub->vectors[x][y].x = x;
				cub->vectors[x][y].y = y;
				assign_types(map[x][y], &cub->vectors[x][y], cub->math);
			}
		}
	}
	cub->vectors[x] = NULL;
}

void	free_vectors(t_vectors **vectors)
{
	int	i;

	i = -1;
	while(vectors[++i])
		free(vectors[i]);
	free(vectors);
}