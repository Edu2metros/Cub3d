/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:56:48 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/05/14 08:43:59 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**fill_info(void)
{
	char	**info;

	info = (char **)ft_safe_malloc(sizeof(char *) * 7);
	info[0] = ft_strdup_two("NO ", get_struct());
	info[1] = ft_strdup_two("SO ", get_struct());
	info[2] = ft_strdup_two("EA ", get_struct());
	info[3] = ft_strdup_two("WE ", get_struct());
	info[4] = ft_strdup_two("C ", get_struct());
	info[5] = ft_strdup_two("F ", get_struct());
	info[6] = NULL;
	return (info);
}

int	find_first_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalnum(str[i]) == 1)
			return (i);
		else if (str[i] == '\t' || str[i] == '\f' || str[i] == '\f')
			return (-1);
		i++;
	}
	return (-1);
}

int	find_map_height(char **map_start)
{
	int	i;
	int	line_counter;

	i = -1;
	line_counter = 0;
	while (map_start[++i])
	{
		if (map_start[i][0] != '\n')
			line_counter++;
	}
	return (line_counter - 1);
}

int	is_a_dif_char(char *s, char c)
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

int	is_error(t_cub *cub, char **info, int i)
{
	if (cub->err_flag == TRUE || ft_array_len(info) != 0
		|| cub->file[i] == NULL)
		return (TRUE);
	return (FALSE);
}
