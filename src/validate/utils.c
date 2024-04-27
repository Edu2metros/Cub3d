#include "../includes/cub3d.h"

int has_in_array(char *str, char **array)
{
	int i;

	i = 0;
	while (array[i] != NULL)
	{
		if (ft_strcmp_until(str, array[i], ' ') == 0)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void pop_string_array(char **directions, char *line)
{
	int i;

	i = 0;
	while (directions[i] != NULL)
	{
		if (ft_strcmp_until(line, directions[i], ' ') == 0)
		{
			shift_args(directions, i);
			break;
		}
		i++;
	}
}

char **fill_directions(void)
{
	char **directions;

	directions = (char **)ft_safe_malloc(sizeof(char *) * 7);
	directions[0] = ft_strdup("NO ");
	directions[1] = ft_strdup("SO ");
	directions[2] = ft_strdup("EA ");
	directions[3] = ft_strdup("WE ");
	directions[4] = ft_strdup("C ");
	directions[5] = ft_strdup("F ");
	directions[6] = NULL;
	return (directions);
}
