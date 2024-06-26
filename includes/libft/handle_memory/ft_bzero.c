/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:16:59 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/04/17 12:37:37 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*c;
	size_t			mem;

	c = (unsigned char *)s;
	mem = 0;
	while (mem < n)
	{
		c[mem] = 0;
		mem++;
	}
}
