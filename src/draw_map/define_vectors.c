#include "../../includes/cub3d.h"

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

void	define_vectors(char **map, t_vectors **vectors)
{
	int	x;
	int	y;
	int	max_x;

	y = -1;
	max_x = find_max_x(map);
	vectors = ft_calloc(1, sizeof(t_vectors **));
	while (map[++y])
	{
		vectors[y] = ft_calloc(max_x, sizeof(t_vectors));
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] != '\n')
			{
				vectors[y][x].x = x;
				vectors[y][x].y = y;
				if (ft_isspace(map[y][x]))
					vectors[y][x].is_space = TRUE;
				else
					vectors[y][x].is_space = FALSE;
			}
		}
	}
}