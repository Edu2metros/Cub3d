#include "../../includes/cub3d.h"

int ft_strcmp_directions(char *line, char *direction)
{
	static char **directions = NULL;
	static int initialized = 0;

	if (!initialized)
	{
		directions = fill_directions();
		initialized = 1;
	}
	if (*directions == NULL)
		return (FALSE);
	if (ft_strcmp_until(line, direction, ' ') == 0 && has_in_array(direction, directions) == TRUE)
	{
		pop_string_array(directions, line);
		return (TRUE);
	}
	return (FALSE);
}

int validate_directions(char *line)
{
	if (ft_strcmp_directions(line, "NO ") == TRUE)
		return (TRUE);
	if (ft_strcmp_directions(line, "SO ") == TRUE)
		return (TRUE);
	if (ft_strcmp_directions(line, "EA ") == TRUE)
		return (TRUE);
	if (ft_strcmp_directions(line, "WE ") == TRUE)
		return (TRUE);
	if (ft_strcmp_directions(line, "C ") == TRUE)
		return (TRUE);
	if (ft_strcmp_directions(line, "F ") == TRUE)
		return (TRUE);
	return (FALSE);
}

void map_is_valid(t_cub *cub)
{
	int i;
	int is_valid;
	int char_pos;

	i = -1;
	is_valid = 0;
	while (cub->file[++i] != NULL)
	{
		if (cub->file[i][0] == '\n')
			continue;
		char_pos = find_first_char(cub->file[i]);
		if (ft_isdigit(cub->file[i][char_pos]) == 1)
			break;
		else
			is_valid += validate_directions(cub->file[i] + char_pos);
	}
	if (cub->err_flag == TRUE || is_valid != TOTAL_INFOS)
		exit_program(cub, "Error in file. Exit\n");
}

