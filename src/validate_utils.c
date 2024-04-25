#include "../includes/cub3d.h"

void	map_is_valid(t_cub *cub)
{
	// mandar a textura e as cores pra uma struct separada (?)
	//flag que já passou pela parte de textura e pela parte de cores (?)
	//se o primeiro char começar com um número, automaticamente considerar que dali pra baixo é um mapa

	int	i;
	int	is_valid;
	int	char_pos;

	i = -1;
	is_valid = 0;
	while(cub->file[++i] != NULL)
	{
		if(cub->file[i][0] == '\n')
			continue;
		char_pos = find_first_char(cub->file[i]);
		if(ft_isdigit(cub->file[i][char_pos])  == 1)
			break ;
		else
			is_valid += map_validate(cub, cub->file[i] + char_pos);
	}
	if(cub->err_flag == TRUE || is_valid != TOTAL_INFOS)
		exit_program(cub, "Error in file. Exit\n");
}

int	validate_cel_n_floor(t_cub *cub, char *line)
{
	int	i;

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
}

int		validate_directions(char *line)
{
	static int verify;
	
	if (ft_strcmp_until(line, "NO ", ' ') == 0)
		return (TRUE);
	else if (ft_strcmp_until(line, "SO ", ' ') == 0)
		return (TRUE);
	else if (ft_strcmp_until(line, "EA ", ' ') == 0)
		return (TRUE);
	else if (ft_strcmp_until(line, "WE ", ' ') == 0)
		return (TRUE);
	return (FALSE);
}

int	map_validate(t_cub *cub, char *line)
{
	int	is_valid;

	is_valid = 0;
	if (line[0] == 'C' || line[0] == 'F')
		is_valid += validate_cel_n_floor(cub, line);
	else
		is_valid += validate_directions(line);
	return (is_valid);
}
