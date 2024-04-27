#include "../includes/cub3d.h"

static void check_file(char *file, t_cub *cub)
{
	int fd;

	if (!ft_strchr(file, '.'))
		exit_program(cub, "Error\nInvalid file extension\n");
	if (ft_strcmp(ft_strrchr(file, '.'), ".cub") != 0)
		exit_program(cub, "Error\nInvalid file extension\n");
	if ((fd = open(file, O_RDONLY)) == -1)
		exit_program(cub, "Error\nFile does not exist\n");
	cub->fd = fd;
}

static void extract_lines(char *file, t_cub *cub)
{
    char *tmp_line;
    int lines;
    int temp_fd;
    int i;

    temp_fd = open(file, O_RDONLY);
    lines = get_how_many_lines(temp_fd);
    cub->file = malloc_garbage_collector(&cub->garbage, sizeof(char *) * (lines + 1));
    i = 0;
    while ((tmp_line = get_next_line(cub->fd)) != NULL)
    {
        cub->file[i] = malloc_garbage_collector(&cub->garbage, ft_strlen(tmp_line) + 1);
        ft_strlcpy(cub->file[i], tmp_line, ft_strlen(tmp_line) + 1);
		free(tmp_line);
		i++;
    }
    cub->file[i] = NULL;
    close(temp_fd);
    close(cub->fd);
}

void check_args(int argc, t_cub *cub)
{
	if (argc != 2)
		exit_program(cub, "Error\nInvalid number of arguments\n");
}

void validation(int argc, char **argv, t_cub *cub)
{
	check_args(argc, cub);
	check_file(argv[1], cub);
	extract_lines(argv[1], cub);
	map_is_valid(cub);
	print_lines(cub);
}