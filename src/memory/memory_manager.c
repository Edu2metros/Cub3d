/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:49:53 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/05/14 08:37:35 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	*ft_safe_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	if (ptr == NULL)
		exit_program(get_struct(), "Error\nCalloc failed\n");
	return (ptr);
}

void	*calloc_gc(t_garbage **garbage_collector, size_t count, size_t size)
{
	void		*ptr;
	t_garbage	*new;

	ptr = ft_safe_calloc(count, size);
	new = (t_garbage *)ft_safe_calloc(1, sizeof(t_garbage));
	new->ptr = ptr;
	new->next = *garbage_collector;
	*garbage_collector = new;
	return (ptr);
}

void	free_gargabe_collector(t_garbage *list)
{
	t_garbage	*temp;

	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp->ptr);
		temp->ptr = NULL;
		free(temp);
		temp = NULL;
	}
}

void	*ft_safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		exit_program(get_struct(), "Error\nMalloc failed\n");
	return (ptr);
}

void	finish_mlx(t_cub *cub)
{
	if (cub->info->no)
		mlx_delete_texture(cub->info->no);
	if (cub->info->so)
		mlx_delete_texture(cub->info->so);
	if (cub->info->we)
		mlx_delete_texture(cub->info->we);
	if (cub->info->ea)
		mlx_delete_texture(cub->info->ea);
	mlx_terminate(cub->mlx);
}
