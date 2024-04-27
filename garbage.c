/* void	map_validation(char *file, t_cub *cub)
{
	// i = 0;
	extract_lines(file, cub);
	map_is_valid(cub);
	print_lines(cub);
	// i = check_texture(cub);
	// check the texture (first 4 lines)
	// if the file exists
	// check the RGB of the sky and the ground (5 and 6 lines)
	// check if is in the range (0-255)
	// check the map
}


int validate_cel_n_floor(t_cub *cub, char *line)
{
	int i;

	i = 0;
	if (line[i] == ' ')
		i++;
	while (line[i] && line[++i])
	{
		if (line[i] == ' ')
			while (line[i] == ' ')
				i++;
		if (!ft_isdigit(line[i]) && line[i] != ',' && line[i] != ' ' && line[i] != '\n')
		{
			cub->err_flag = TRUE;
			return (FALSE);
		}
	}
	return (TRUE);
} */