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

static void	assign_types(char type, t_vectors *vectors)
{
	if (ft_isspace(type))
		vectors->type = SPACE;
	else if (type == '0')
		vectors->type = FLOOR;
	else if (type == '1')
		vectors->type = WALL;
	else
	{
		printf("ASSIGN TYPES FUNCTION:");
		printf("Player found\n");
		printf("Player x: %d\n", vectors->x);
		printf("Player y: %d\n", vectors->y);
		vectors->type = PLAYER;
	}
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
	cub->vectors = calloc_garbage_collector(&cub->garbage, y + 1, sizeof(t_vectors *));
	y = -1;
	while (map[++y])
	{
		cub->vectors[y] = calloc_garbage_collector(&cub->garbage, max_x, sizeof(t_vectors));
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