/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:16:22 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/04/30 19:43:45 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_map(char **file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		printf("%s\n", file[i]);
		i++;
	}
}

void	print_infos(t_info *info)
{
	printf("NO: %s\n", info->no);
	printf("SO: %s\n", info->so);
	printf("WE: %s\n", info->we);
	printf("EA: %s\n", info->ea);
	printf("F: %d, %d, %d\n", info->flo[0], info->flo[1], info->flo[2]);
	printf("C: %d, %d, %d\n", info->cel[0], info->cel[1], info->cel[2]);
}

void	cub3d(t_cub *cub)
{
	parser(cub);
	define_vectors(cub->info->map, cub);
	printf("cub_vecs: %p\n", cub->vectors);
	// print_infos(cub->info);
	print_map(cub->info->map);
	// init_window(cub->vectors);

}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = validation(argc, argv);
	cub3d(cub);
	free_gargabe_collector(cub->garbage);
	return (EXIT_SUCCESS);
}
