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
		i++;
	}
	return (-1);
}



void	check_texture_color(t_cub *cub)
{
	// mandar a textura e as cores pra uma struct separada (?)
	//flag que já passou pela parte de textura e pela parte de cores (?)
	//se o primeiro char começar com um número, automaticamente considerar que dali pra baixo é um mapa

	int	i;
	int char_pos;
	i = -1;
	while(cub->file[i++] != NULL)
	{
		if(cub->file[i][0] == '\n')
			continue;
		char_pos = find_first_char(cub->file[i]);
		if(ft_isdigit(cub->file[i][char_pos]) == 1) //apartir dali começa numero, entao considerar que dali pra baixo é mapa
			break ;
		else
		{
			if(cub->file[i][char_pos] == 'C')
				;
				//fazer a validação se ali dentro tá tudo certo, cor dentro do range, se n tem um caractere estranho e etc. Se tiver tudo ok, uma variável de outra struct tem um ponteiro apontando pra cub->file[i]
			else if(cub->file[i][char_pos] == 'F')
				;
				//mesma coisa
			// else if(NO, SO, WE, EA)
			//else exit (alguma coisa de estranha está onde nao deveria estar)
		}
	}
	//uma função que checa se todas as flags são todas iguais a 1, se tiver um igual a 0 ou maior que 1, erro.
}
