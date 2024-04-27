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
		return (TRUE);
	else if (ft_strcmp_directions(line, "F ", info) == TRUE)
		return (TRUE);
    else
    {
        cub->err_flag = TRUE;
        return (FALSE);
    
    }
}

void map_is_valid(t_cub *cub)
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
			break;
		else
		    validate_directions(cub->file[i] + char_pos, info, cub);
	}
	//Se o arquivo tiver mais de 0 strings na matriz ou se o arquivo tiver um erro, o programa é encerrado.
	if (cub->err_flag == TRUE || ft_array_len(info) != 0)
	{
		free_array(info);
		exit_program(cub, "Error in file. Exit\n");
	}
	free(info);
}

