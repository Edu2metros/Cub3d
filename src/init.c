/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:07:01 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/04/29 16:21:10 by eddos-sa         ###   ########.fr       */
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
	cub = (t_cub *)malloc_garbage_collector(&garbage, sizeof(t_cub));
	cub->garbage = garbage;
	cub->fd = 0;
	cub->err_flag = FALSE;
	*get_struct() = *cub;
	cub->info = (t_info *)malloc_garbage_collector(&cub->garbage,
			sizeof(t_info));
	cub->info->cel = (int *)malloc_garbage_collector(&cub->garbage, sizeof(int)
			* 3);
	cub->info->flo = (int *)malloc_garbage_collector(&cub->garbage, sizeof(int)
			* 3);
	return (cub);
}
