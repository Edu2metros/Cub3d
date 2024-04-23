/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:54:23 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/04/17 12:39:46 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	int		*p;
	size_t	overflow;

	overflow = nitems * size;
	if (nitems != 0 && (overflow / nitems) != size)
		return (NULL);
	p = malloc(nitems * size);
	if (p == NULL)
		return (p);
	ft_bzero(p, size * nitems);
	return (p);
}
