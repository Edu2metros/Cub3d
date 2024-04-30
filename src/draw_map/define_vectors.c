#include "../../includes/cub3d.h"

void	free_vectors(t_vectors **vectors);

static int	find_max_x(char **map)
{
	int	i;
	int	j;
	int	result;
	int	counter;

	i = -1;
	result = 0;
	while (map[++i])
	{
		j = -1;
		counter = ft_strlen(map[i]);
		if (counter > result)
			result = counter;
	}
	return (result);
}

static void	assign_types(char type, t_vectors *vectors)
{
	if (ft_isspace(type))
		vectors->type = SPACE;
	else if (type == '0')
		vectors->type = FLOOR;
	else if (type == '1')
		vectors->type = WALL;
	else
		vectors->type = PLAYER;
}

void	define_vectors(char **map, t_cub *cub)
{
	int	x;
	int	y;
	int	max_x;

	y = -1;
	max_x = find_max_x(map);
	while (map[++y])
		;
	cub->vectors = ft_calloc(y + 1, sizeof(t_vectors *));
	y = -1;
	while (map[++y])
	{
		cub->vectors[y] = ft_calloc(max_x, sizeof(t_vectors));
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] != '\n')
			{
				cub->vectors[y][x].x = x;
				cub->vectors[y][x].y = y;
				assign_types(map[y][x], &cub->vectors[y][x]);
			}
		}
	}
	cub->vectors[y] = NULL;
	free_vectors(cub->vectors);
	// printf("Vectors: %p\n", vectors);
}

void	free_vectors(t_vectors **vectors)
{
	int	i;

	i = -1;
	while(vectors[++i])
		free(vectors[i]);
	free(vectors);
}