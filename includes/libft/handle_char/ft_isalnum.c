/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:56:46 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/04/17 16:46:37 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isalnum(int digit)
{
	if ((digit >= 'a' && digit <= 'z') || (digit >= 'A' && digit <= 'Z'))
		return (1);
	else if (digit >= '0' && digit <= '9')
		return (1);
	else
		return (0);
}
