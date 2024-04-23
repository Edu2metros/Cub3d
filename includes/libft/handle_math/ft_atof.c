/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:16:51 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/04/17 16:47:20 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long double	ft_atof(char *str)
{
	unsigned int	i;
	long double		sign;
	long double		result;
	long double		divisor;

	divisor = 0.1;
	i = 0;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = ((str[i] == '+' || ft_isdigit(str[i])) - (str[i] == '-'));
	if ((str[i] == '+') || (str[i] == '-'))
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]) && str[i] != '.')
		result = result * 10 + (str[i++] - '0');
	if (str[i] == '.')
	{
		while (str[++i] != '\0' && ft_isdigit(str[i]))
		{
			result += (str[i] - '0') * divisor;
			divisor /= 10;
		}
	}
	return (result * sign);
}
