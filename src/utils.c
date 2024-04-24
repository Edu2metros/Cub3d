#include "../includes/cub3d.h"

t_cub	*get_struct(void)
{
	static t_cub	cub;

	return (&cub);
}

void	*ft_safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		ft_printf_fd(STDERR_FILENO, "Error\nMalloc failed\n");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}
// levando em conta que o probleminha da GNL tá consertado

int find_first_char(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if(ft_isalnum(str[i]) == 1)
			return (i);
		else if(str[i] == '\t' || str[i] == '\f' || str[i] == '\f')
			return(-1);
		i++;
	}
	return (-1);
}

void exit_program(t_cub *cub, char *str)
{
	ft_printf_fd(STDERR_FILENO, "%s", str);
	free_array(cub->file);
	free(cub);
	exit(EXIT_FAILURE);
}


void	check_texture_color(t_cub *cub)
{
	// mandar a textura e as cores pra uma struct separada (?)
	//flag que já passou pela parte de textura e pela parte de cores (?)
	//se o primeiro char começar com um número, automaticamente considerar que dali pra baixo é um mapa

	int	i;
	int char_pos;

	i = -1;
	while(cub->file[++i] != NULL)
	{
		if(cub->file[i][0] == '\n')
			continue;
		char_pos = find_first_char(cub->file[i]);
		if(ft_isdigit(cub->file[i][char_pos]) == 1) //apartir dali começa numero, entao considerar que dali pra baixo é mapa
			break ;
		else
			validate_colors(cub, cub->file[i][char_pos]);
	}
	//uma função que checa se todas as flags são todas iguais a 1, se tiver um igual a 0 ou maior que 1, erro.
}

void	validate_cel_n_floor(t_cub *cub, char *line)
{
	int	i;

	i = 0;
	if (line[i] == ' ')
		i++;
	while (line[i] && line[++i])
	{
		if (!ft_isdigit(line[i]) || line[i] != ',')
			cub->clr_flag = ERROR;
	}
}

void	validate_colors(t_cub *cub, char *line)
{
	int	i;
	char **directions;

	directions = ft_safe_malloc(sizeof(char *) * 5);
	directions[0] = "NO";
	directions[1] = "SO";
	directions[2] = "WE";
	directions[3] = "EA";
	directions[4] = NULL;
	if (line[0] == 'C' || line[0] == 'F')
		validate_cel_n_floor(cub, line);
	else
	{	
		i = -1;
		while (directions[++i])
		{
			if (ft_strcmp_until(line, directions[i], ' ') != 0)
				cub->clr_flag = ERROR;
		}
	}
}