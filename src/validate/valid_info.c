/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:55:52 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/04/29 19:28:19 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	range_color(t_cub *cub, char *line)
{
	char	**colors;
	int		i;

	colors = ft_split(line, ',');
	i = 0;
	if (ft_array_len(colors) != 3)
	{
		cub->err_flag = TRUE;
		free_array(colors);
		return (FALSE);
	}
	while (colors[i])
	{
		if (ft_atof(colors[i]) < 0 || ft_atof(colors[i]) > 255)
		{
			cub->err_flag = TRUE;
			free_array(colors);
			return (FALSE);
		}
		i++;
	}
	free_array(colors);
	return (TRUE);
}

static int	ft_strcmp_directions(char *line, char *direction, char **info)
{
	if (*info == NULL)
		return (FALSE);
	if (ft_strcmp_until(line, direction, ' ') == 0 && has_in_array(direction,
			info) == TRUE)
	{
		pop_string_array(info, line);
		return (TRUE);
	}
	return (FALSE);
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
		if (!ft_isdigit(line[i]) && line[i] != ',' && line[i] != ' '
			&& line[i] != '\n')
		{
			cub->err_flag = TRUE;
			return (FALSE);
		}
	}
	if (range_color(cub, line) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	validate_info(char *line, char **info, t_cub *cub)
{
	if (ft_strcmp_directions(line, "NO ", info) == TRUE)
		return (TRUE);
	else if (ft_strcmp_directions(line, "SO ", info) == TRUE)
		return (TRUE);
	else if (ft_strcmp_directions(line, "EA ", info) == TRUE)
		return (TRUE);
	else if (ft_strcmp_directions(line, "WE ", info) == TRUE)
		return (TRUE);
	else if (ft_strcmp_directions(line, "C ", info) == TRUE
		|| ft_strcmp_directions(line, "F ", info) == TRUE)
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
