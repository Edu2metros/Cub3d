/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:06:27 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/05/02 14:51:19 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	exit_program(t_cub *cub, char *str)
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

char	*ft_strdup_two(const char *str, t_cub *cub)
{
	char	*strdup;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0')
		i++;
	strdup = (char *)calloc_garbage_collector(&cub->garbage, (i + 1),
			sizeof(char));
	if (strdup == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		strdup[j] = str[j];
		j++;
	}
	strdup[j] = '\0';
	return (strdup);
}

void	remove_char(char *str, char c)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] != c)
		{
			str[j] = str[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
}

int	jump_lines(char **file)
{
	int	i;
	int	first_char;

	i = -1;
	while (file[++i] != NULL)
	{
		if (file[i][0] == '\n' && file[i][1] == '\0')
			continue ;
		first_char = find_first_char(file[i]);
		if (ft_isdigit(file[i][first_char]))
			break ;
	}
	return (i);
}
