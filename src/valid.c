#include "../includes/cub3d.h"

static void	check_file(char *file, t_cub *cub)
{
	int		fd;

	if (!ft_strchr(file, '.'))
	{
		ft_printf_fd(STDERR_FILENO, "Error\nInvalid file extension\n");
		free(cub);
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp(ft_strrchr(file, '.'), ".cub") != 0)
	{
		ft_printf_fd(STDERR_FILENO, "Error\nInvalid file extension\n");
		free(cub);
		exit(EXIT_FAILURE);
	}
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_printf_fd(STDERR_FILENO, "Error\nInvalid file\n");
		free(cub);
		exit(EXIT_FAILURE);
	}
	cub->fd = fd;
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

static void	extract_lines(char *file, t_cub *cub)
{
	int	lines;
	int	temp_fd;
	int	i;

	temp_fd = open(file, O_RDONLY);
	lines = get_how_many_lines(temp_fd);
	cub->file = ft_safe_malloc(sizeof(char *) * (lines + 1));
	i = 0;
	while ((cub->file[i] = get_next_line(cub->fd)) != NULL)
		i++;
	cub->file[i] = NULL;
	close(temp_fd);
	close(cub->fd);
}

void	map_validation(char *file, t_cub *cub)
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

void	validation(int argc, char **argv, t_cub *cub)
{
	if (argc != 2)
	{
		ft_printf_fd(STDERR_FILENO, "Error\nInvalid number of arguments\n");
		free(cub);
		exit(EXIT_FAILURE);
	}
	check_file(argv[1], cub);
	map_validation(argv[1], cub);
}