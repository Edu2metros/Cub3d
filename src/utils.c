#include "../includes/cub3d.h"

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
	free_gargabe_collector(cub->garbage);
	exit(EXIT_FAILURE);
}

void	print_lines(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->file[i])
	{
		printf("%s\n", cub->file[i]);
		i++;
	}
}
