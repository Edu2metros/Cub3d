/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:16:22 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/05/14 09:48:21 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* 
arrumar quando o player nascer perto de parede e não conseguir andar direito
arrumar a direção inicial do player olhando
*/

static void	ft_mlx_handler(t_cub *cub)
{
	mlx_loop_hook(cub->mlx, keys, cub);
	mlx_loop(cub->mlx);
	finish_mlx(cub);
}

static int	cub3d(int argc, char **argv)
{
	t_cub	*cub;

	cub = init();
	validation(argc, argv, cub);
	ft_mlx_init(cub);
	parser(cub);
	define_vectors(cub->info->map, cub);
	define_variable_math(cub);
	draw_frame(cub);
	ft_mlx_handler(cub);
	free_gargabe_collector(cub->garbage);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	cub3d(argc, argv);
	return (EXIT_SUCCESS);
}
