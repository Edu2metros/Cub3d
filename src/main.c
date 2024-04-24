/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:16:22 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/04/24 19:57:13 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_cub *cub;
	cub = (t_cub *)ft_safe_malloc(sizeof(t_cub));
	// cub = init(cub);
	validation(argc, argv, cub);
	// assing_colors();
	free(cub);
	// Cub3d function (entire project here)
	// finish
	return (EXIT_SUCCESS);
}
