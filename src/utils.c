/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:06:27 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/04/28 01:06:31 by eddos-sa         ###   ########.fr       */
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
