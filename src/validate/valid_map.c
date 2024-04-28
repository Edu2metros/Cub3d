#include "../../includes/cub3d.h"

static int ft_strcmp_directions(char *line, char *direction, char **info)
{
	//verificação pra seg fault e se caso mandar mais informações do que a string tem.
	if (*info == NULL)
		return (FALSE);
	if (ft_strcmp_until(line, direction, ' ') == 0 && has_in_array(direction, info) == TRUE)
	{
		pop_string_array(info, line);
		return (TRUE);
	}
	return (FALSE);
}

int range_color(t_cub *cub, char *line)
{
	char **colors;
	int i;
	
	colors = ft_split(line, ',');
	i = 0;
	if(ft_array_len(colors) != 3)
	{
		cub->err_flag = TRUE;
		free_array(colors);
		return(FALSE);
	}
	while(colors[i])
	{
		if(ft_atof(colors[i]) < 0 || ft_atof(colors[i]) > 255)
		{
			cub->err_flag = TRUE;
			free_array(colors);
			return(FALSE);
		}
		i++;
	}
	free_array(colors);
	return (TRUE);
}

static int	validate_cel_n_floor(t_cub *cub, char *line)
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
	if(range_color(cub, line) == FALSE)
		return (FALSE);
	return (TRUE);
}

static int validate_directions(char *line, char **info, t_cub *cub)
{
	if (ft_strcmp_directions(line, "NO ", info) == TRUE)
		return (TRUE);
	else if (ft_strcmp_directions(line, "SO ", info) == TRUE)
		return (TRUE);
	else if (ft_strcmp_directions(line, "EA ", info) == TRUE)
		return (TRUE);
	else if (ft_strcmp_directions(line, "WE ", info) == TRUE)
		return (TRUE);
	else if (ft_strcmp_directions(line, "C ", info) == TRUE)
	{
		if (!validate_cel_n_floor(cub, line))
			return (FALSE);
		return (TRUE);
	}
	else if (ft_strcmp_directions(line, "F ", info) == TRUE)
	{
		if (!validate_cel_n_floor(cub, line))
			return (FALSE);
		return (TRUE);
	}
	else
	{
		cub->err_flag = TRUE;
		return (FALSE);
	}
}

/*
	is_valid_characters

	param map_start -> ponto inicial onde iniciam-se os vetores

	o loop while roda por todo o mapa, e utiliza a string
	valid_chars para identificar através da funcao strchr
	se os caracteres dentro do mapa são todos válidos, caso identifique um caractere que não é esperado (identificado os esperados dentro da string valid_chars) retorna FALSE.
*/

int	is_valid_characters(char **map_start)
{
	int	i;
	int	j;
	i = -1;
	while (map_start[++i])
	{
		j = -1;
		while (map_start[i][++j])
		{
			if (!ft_strchr(VALID_CHARS, map_start[i][j]))
				return (FALSE);
		}
	}
	return (TRUE);
}

/*
	is_more_than_one_player

	param map_start -> ponto inicial onde iniciam-se os vetores

	o loop while roda por todo o mapa, e utiliza a string
	player_chars para identificar através da funcao strchr
	quantos players o mapa possuí, se possuir algum valor diferente de 1 que é o esperado, considera erro.
	(o player pode ser identificado por qualquer um desses caracteres: N, S, E, W)
*/

int is_more_than_one_player(char **map_start)
{
	int	i;
	int	j;
	int	player_counter;
	i = -1;
	player_counter = 0;
	while (map_start[++i])
	{
		j = -1;
		while (map_start[i][++j])
			if (ft_strchr(PLAYER_CHARS, map_start[i][j]))
				player_counter++;
	}
	if (player_counter != 1)
		return (TRUE);
	return (FALSE);
}

/*
	find_map_height

	seu retorno é + 1 por conta que 
	a última linha não contém '\n'
*/

int map_adjust(char **map_start, int line_counter)
{
	while(!map_start[line_counter])
		line_counter--;
	return (line_counter);
}

int	find_map_height(char **map_start)
{
	int	i;
	int	line_counter;

	i = -1;
	line_counter = 0;
	while (map_start[++i])
	{
		if (ft_strchr(map_start[i], '\n'))
			line_counter++;
	}
	line_counter = map_adjust(map_start, line_counter);
	return (line_counter);
}

int is_a_dif_char(char *s, char c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] != c && s[i] != '\n' && s[i] != ' ')
			return (FALSE);
	}
	return (TRUE);
}

/*
	is_extremities_closed

	Checa se as linhas do topo e do final contém
	apenas paredes
*/

int	is_extremities_closed(char *top_line, char *bot_line)
{
	if (is_a_dif_char(top_line, '1') == FALSE || is_a_dif_char(bot_line, '1') == FALSE)
		return (FALSE);
	return (TRUE);
}

/*
	is_all_land_closed

	até o momento checa se existe um espaco ao redor dos numeros zeros que definem o piso do mapa, precisa de refatoracao e aprimoramentos.
*/

int ft_isspace_two(char **map_start, int i, int j)
{
	if (!map_start[i - 1][j] || !map_start[i + 1][j] || !map_start[i][j - 1] || !map_start[i][j + 1])
		return (FALSE);
	if (map_start[i - 1][j] == ' ' || map_start[i + 1][j] == ' ' || map_start[i][j - 1] == ' ' || map_start[i][j + 1] == ' ')
		return (FALSE);
	return (TRUE);
}

int ft_isvalid(char c)
{
	return(c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_all_land_closed(char **map_start)
{
	int	i;
	int	j;
	int	map_height;

	map_height = find_map_height(map_start);
	if (is_extremities_closed(map_start[0], map_start[map_height]) == FALSE)
		return (FALSE);
	i = 0;	
	while(map_start[++i] && i < map_height)
	{
		j = -1;
		while (map_start[i][++j])
		{
			if (ft_isvalid(map_start[i][j]) && ft_isspace_two(map_start, i, j) == FALSE)
				return (FALSE);	
		}
	}
	return (TRUE);
}

void	validate_map(t_cub *cub, char **map_start)
{
	if (!is_valid_characters(map_start))
		cub->err_flag = TRUE;
	else if (is_more_than_one_player(map_start))
		cub->err_flag = TRUE;
	else if (!is_all_land_closed(map_start))
		cub->err_flag = TRUE;
}

void	map_is_valid(t_cub *cub)
{
	int i;
	int char_pos;
	//Matriz de strings que contém uma base de strings que devem ser encontradas no arquivo, 
	//se achar uma string que não está na matriz ou tiver duas strings iguais, o arquivo é inválido.
	//Quando acha uma string e ela é válida, ela é removida da matriz com a função pop_string_array().
    char **info = fill_info();
	i = -1;
	while (cub->file[++i] != NULL && cub->err_flag == FALSE)
	{
		if (cub->file[i][0] == '\n')
			continue;
		char_pos = find_first_char(cub->file[i]);
		if (ft_isdigit(cub->file[i][char_pos]) == 1)
		{
			validate_map(cub, &cub->file[i]);
			break;
		}
		else
		    validate_directions(cub->file[i] + char_pos, info, cub);
	}
	//Se o arquivo tiver mais de 0 strings na matriz ou se o arquivo tiver um erro, o programa é encerrado.
	//Adicionei mais uma verificação para se caso o arquivo não tiver mais linhas para ler, o que significa que não existe um mapa no arquivo.
	if (cub->err_flag == TRUE || ft_array_len(info) != 0 || cub->file[i] == NULL)
	{
		free_array(info);
		exit_program(cub, "Error in file. Exit\n");
	}
	free(info);
}

