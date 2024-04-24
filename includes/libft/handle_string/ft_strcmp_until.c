/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 03:19:30 by jaqribei          #+#    #+#             */
/*   Updated: 2024/04/24 20:00:59 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strcmp_until(char *s1, char *s2, char stop)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0' || (s1[i] == stop && s2[i] == stop))
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}
