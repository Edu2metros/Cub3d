/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:25:48 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/04/28 01:07:33 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

int	has_in_array(char *str, char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		if (ft_strcmp_until(str, array[i], ' ') == 0)
			return (1);
		i++;
	}
	return (0);
}

void	pop_string_array(char **directions, char *line)
{
	int	i;

	i = 0;
	while (directions[i] != NULL)
	{
		if (ft_strcmp_until(line, directions[i], ' ') == 0)
		{
			shift_args(directions, i);
			break ;
		}
		i++;
	}
}
