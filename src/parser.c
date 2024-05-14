/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:18:22 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/05/14 08:11:40 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static mlx_texture_t	*assign_textures(char *line, t_cub *cub)
{
	char			*path;
	mlx_texture_t	*result;
	int				first_char;

	first_char = find_first_char(line + 2);
	path = ft_strdup(line + 2 + first_char);
	remove_char(path, '\n');
	result = mlx_load_png(path);
	free(path);
	if (result == NULL)
	{
		finish_mlx(cub);
		exit_program(cub, "MLX error loading texture\n");
	}
	return (result);
}

static void	assign_colors(char *line, int *i)
{
	char	**colors;
	int		first_char;

	first_char = find_first_char(line + 1);
	remove_char(line + 1 + first_char, ' ');
	colors = ft_split(line + 1 + first_char, ',');
	i[0] = ft_atoi(colors[0]);
	i[1] = ft_atoi(colors[1]);
	i[2] = ft_atoi(colors[2]);
	free_array(colors);
}

static void	parser_info(t_cub *cub)
{
	int	i;
	int	first_char;

	i = -1;
	while (cub->file[++i] != NULL)
	{
		first_char = find_first_char(cub->file[i]);
		if (cub->file[i][0] == '\n' && cub->file[i][1] == '\0')
			continue ;
		if (ft_isdigit(cub->file[i][first_char]))
			break ;
		if (ft_strcmp_until(cub->file[i], "NO ", ' ') == 0)
			cub->info->no = assign_textures(cub->file[i], cub);
		else if (ft_strcmp_until(cub->file[i], "SO ", ' ') == 0)
			cub->info->so = assign_textures(cub->file[i], cub);
		else if (ft_strcmp_until(cub->file[i], "WE ", ' ') == 0)
			cub->info->we = assign_textures(cub->file[i], cub);
		else if (ft_strcmp_until(cub->file[i], "EA ", ' ') == 0)
			cub->info->ea = assign_textures(cub->file[i], cub);
		else if (ft_strcmp_until(cub->file[i], "F ", ' ') == 0)
			assign_colors(cub->file[i], cub->info->flo);
		else if (ft_strcmp_until(cub->file[i], "C ", ' ') == 0)
			assign_colors(cub->file[i], cub->info->cel);
	}
}

static void	parser_map(t_cub *cub)
{
	int	i;
	int	start;
	int	map_height;

	i = 0;
	start = jump_lines(cub->file);
	map_height = find_map_height(cub->file + start);
	cub->info->map = calloc_gc(&cub->garbage, map_height + 2, sizeof(char *));
	while (i < map_height + 1)
	{
		cub->info->map[i] = ft_strdup_two(cub->file[start + i], cub);
		i++;
	}
}

void	parser(t_cub *cub)
{
	parser_info(cub);
	parser_map(cub);
}
