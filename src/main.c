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

//Garbage collector:
//Lista linkada para armazenas os ponteiros alocados
//para liberar a memória no final do programa

void *malloc_garbage_collector(t_garbage **garbage_collector, size_t size)
{
	void *ptr = ft_safe_malloc(size);
	t_garbage *new = (t_garbage *)ft_safe_malloc(sizeof(t_garbage));
	new->ptr = ptr;
	new->next = *garbage_collector;
	*garbage_collector = new;
	return ptr;
}

void free_gargabe_collector(t_garbage *list)
{
	while (list != NULL)
	{
		t_garbage *temp = list;
		list = list->next;
		free(temp->ptr);
		free(temp);
	}
}

int main(int argc, char **argv)
{
	t_cub *cub;

	cub = init();
	validation(argc, argv, cub);
	// assing_colors();
	free_gargabe_collector(cub->garbage);
	// Cub3d function (entire project here)
	// finish
	return (EXIT_SUCCESS);
}
