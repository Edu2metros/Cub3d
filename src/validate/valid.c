/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:57:02 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/05/14 08:44:27 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_file(char *file, t_cub *cub)
{
	int	fd;

	if (!ft_strchr(file, '.'))
		exit_program(cub, MSG_ERROR "nInvalid file extension\n");
	if (ft_strcmp(ft_strrchr(file, '.'), ".cub") != 0)
		exit_program(cub, MSG_ERROR "nInvalid file extension\n");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_program(cub, MSG_ERROR "nFile does not exist\n");
	cub->fd = fd;
}

static void	extract_lines(char *file, t_cub *cub)
{
	char	*tmp_line;
	int		lines;
	int		temp_fd;
	int		i;

	temp_fd = open(file, O_RDONLY);
	lines = get_how_many_lines(temp_fd);
	cub->file = calloc_gc(&cub->garbage, lines + 1, sizeof(char *));
	i = 0;
	tmp_line = get_next_line(cub->fd);
	while (tmp_line != NULL)
	{
		cub->file[i] = calloc_gc(&cub->garbage, ft_strlen(tmp_line) + 1,
				sizeof(char));
		ft_strlcpy(cub->file[i], tmp_line, ft_strlen(tmp_line) + 1);
		free(tmp_line);
		tmp_line = get_next_line(cub->fd);
		i++;
	}
	cub->file[i] = NULL;
	close(temp_fd);
	close(cub->fd);
}

static void	check_args(int argc, t_cub *cub)
{
	if (argc != 2)
		exit_program(cub,
			MSG_ERROR "Invalid number of arguments!\n \
The correct format is ./cub3D <map/map.cub>\n");
}

static void	map_is_valid(t_cub *cub)
{
	char	**info;
	int		char_pos;
	int		i;

	info = fill_info();
	i = -1;
	while (cub->file[++i] != NULL && cub->err_flag == FALSE)
	{
		if (cub->file[i][0] == '\n')
			continue ;
		char_pos = find_first_char(cub->file[i]);
		if (ft_isdigit(cub->file[i][char_pos]) == 1)
		{
			validate_map(cub, &cub->file[i]);
			break ;
		}
		validate_info(cub->file[i] + char_pos, info, cub);
	}
	if (is_error(cub, info, i) == TRUE)
	{
		free_array(info);
		exit_program(cub,
			MSG_ERROR "There is something wrong in file. Exit.\n");
	}
	free(info);
}

void	validation(int argc, char **argv, t_cub *cub)
{
	check_args(argc, cub);
	check_file(argv[1], cub);
	extract_lines(argv[1], cub);
	map_is_valid(cub);
}
