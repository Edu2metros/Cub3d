/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:49:53 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/04/28 00:55:24 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// Garbage collector:
// Lista linkada para armazenas os ponteiros alocados
// para liberar a memória no final do programa

void	*malloc_garbage_collector(t_garbage **garbage_collector, size_t size)
{
	void		*ptr;
	t_garbage	*new;

	ptr = ft_safe_malloc(size);
	new = (t_garbage *)ft_safe_malloc(sizeof(t_garbage));
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
		free(temp);
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
