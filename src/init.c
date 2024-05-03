/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:07:01 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/05/03 15:42:15 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_cub	*get_struct(void)
{
	static t_cub	cub;

	return (&cub);
}

t_cub	*init(void)
{
	t_cub		*cub;
	t_garbage	*garbage;

	garbage = NULL;
	cub = (t_cub *)calloc_garbage_collector(&garbage, 1, sizeof(t_cub));
	cub->garbage = garbage;
	cub->fd = 0;
	cub->err_flag = FALSE;
	*get_struct() = *cub;
	cub->info = (t_info *)calloc_garbage_collector(&cub->garbage,
			1, sizeof(t_info));
	cub->info->cel = (int *)calloc_garbage_collector(&cub->garbage, 3, sizeof(int));
	cub->info->flo = (int *)calloc_garbage_collector(&cub->garbage, 3, sizeof(int));
	cub->math = (t_math *)calloc_garbage_collector(&cub->garbage,
			1, sizeof(t_math));
	return (cub);
}
