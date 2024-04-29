/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:16:22 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/04/29 16:26:26 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub3d(t_cub *cub)
{
	parser(cub);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = validation(argc, argv);
	free_gargabe_collector(cub->garbage);
	return (EXIT_SUCCESS);
}
