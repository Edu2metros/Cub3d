/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:16:22 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/05/13 22:34:01 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_mlx_init(t_cub *cub)
{
	cub->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", FALSE);
	if (cub->mlx == NULL)
		exit_program(cub, "Error\nmlx_init failed\n");
	cub->img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	if (cub->img == NULL)
		exit_program(cub, "Error\nmlx_new_image failed\n");
}

void	ft_mlx_handler(t_cub *cub)
{
	mlx_loop_hook(cub->mlx, keys, cub);
	mlx_loop(cub->mlx);
	finish_mlx(cub);
}

void	cub3d(int argc, char **argv)
{
	t_cub	*cub;

	cub = init();
	validation(argc, argv, cub);
	ft_mlx_init(cub);
	parser(cub);
	define_vectors(cub->info->map, cub);
	draw_frame(cub);
	ft_mlx_handler(cub);
	free_gargabe_collector(cub->garbage);
}

int	main(int argc, char **argv)
{
	cub3d(argc, argv);
	return (EXIT_SUCCESS);
}